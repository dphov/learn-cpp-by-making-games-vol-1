//
// Created by Dmitry Petukhov on 29/03/2020.
//

#include <iostream>
#include <ctime>
#include <cstring>
#include <cmath>

#include "TextInvaders.h"
#include "CursesUtils.h"

using namespace std;

void InitGame(Game & game);
void InitPlayer(const Game & game, Player & player);
void ResetPlayer(const Game & game, Player & player);
void ResetMissile(Player & player);
int HandleInput(const Game & game, Player & player);
void UpdateGame(const Game & game, Player & player, Shield shields[], int numberOfShields);
void DrawGame(const Game & game, const Player & player, Shield shields[], int numberOfShields);
void MovePlayer(const Game & game, Player & player, int dx);
void PlayerShoot(Player &player);
void DrawPlayer(const Player & player, const char * sprite[]);
void UpdateMissile(Player & player);
void InitShields(const Game & game, Shield shields[], int numberOfShields);
void CleanUpShields(Shield shields[], int numberOfShields);
void DrawShields(const Shield shields[], int numberOfShields);
// returns the shield index of which shield got hit
// return NOT_IN_PLAY if nothing was hit
// also returns the shield collision point

int IsCollision(const Position &projectile, const Shield shields[], int numberOfShields, Position &shieldCollisionPoint);

void ResolveShieldCollision(Shield shields[], int shieldIndex, const Position & shieldCollisionPoint);

int main()
{
    Game game;
    Player player;
    Shield shields[NUM_SHIELDS];
    
    
    CursesUtils::InitializeCurses(true);
    
    InitGame(game);
    InitPlayer(game, player);
    InitShields(game, shields, NUM_SHIELDS);
    
    bool quit = false;
    char input;
    
    clock_t lastTime = clock();
    
    while(!quit)
    {
        input = HandleInput(game, player);
        if(input != 'q')
        {
            clock_t currentTime = clock();
            clock_t dt = currentTime - lastTime;
            
            if(dt > CLOCKS_PER_SEC/FPS)
            {
                lastTime = currentTime;
                
                UpdateGame(game, player, shields, NUM_SHIELDS);
                CursesUtils::ClearScreen();
                DrawGame(game, player, shields, NUM_SHIELDS);
                CursesUtils::RefreshScreen();
            }
        }
        else
        {
            quit = true;
        }
    }
    
    CleanUpShields(shields, NUM_SHIELDS);
    CursesUtils::ShutdownCurses();
    
    return 0;
}

void InitGame(Game & game)
{
    game.windowSize.width = CursesUtils::ScreenWidth();
    game.windowSize.height = CursesUtils::ScreenHeight();
    game.level = 1;
    game.currentState = GS_PLAY; // todo: change to GS_INTRO at the end
}

void InitPlayer(const Game & game, Player & player)
{
    player.lives = MAX_NUMBER_OF_LIVES;
    player.spriteSize.width = PLAYER_SPRITE_WIDTH;
    player.spriteSize.height = PLAYER_SPRITE_HEIGHT;
    ResetPlayer(game, player);
}

void ResetPlayer(const Game & game, Player & player)
{
    player.position.x = game.windowSize.width / 2 - player.spriteSize.width / 2;
    player.position.y = game.windowSize.height - player.spriteSize.height - 1;
    player.animation = 0;
    ResetMissile(player);
}

void ResetMissile(Player & player)
{
    player.missile.x = NOT_IN_PLAY;
    player.missile.y = NOT_IN_PLAY;
}

int HandleInput(const Game & game, Player & player)
{
    int input = CursesUtils::GetChar();
    switch(input)
    {
        case 'q':
            return input;
        case CursesUtils::AK_LEFT:
            MovePlayer(game, player, -PLAYER_MOVEMENT_AMOUNT);
            break;
        case CursesUtils::AK_RIGHT:
            MovePlayer(game, player, PLAYER_MOVEMENT_AMOUNT);
            break;
        case ' ':
            PlayerShoot(player);
    }
    return input;
}
void UpdateGame(const Game & game, Player & player, Shield shields[], int numberOfShields)
{
    UpdateMissile(player);
    
    Position shieldCollisionPoint;
    
    int shieldIndex = IsCollision(player.missile, shields, numberOfShields, shieldCollisionPoint);
    if(shieldIndex != NOT_IN_PLAY)
    {
        ResetMissile(player);
        ResolveShieldCollision(shields, shieldIndex, shieldCollisionPoint);
    }
}
void DrawGame(const Game & game, const Player & player, Shield shields[], int numberOfShields)
{
    DrawPlayer(player, PLAYER_SPRITE);
    DrawShields(shields, NUM_SHIELDS);
}
void MovePlayer(const Game & game, Player & player, int dx)
{
    if (player.position.x + player.spriteSize.width + dx > game.windowSize.width) // make sure player doesn't go off the screen to the right
    {
        player.position.x = game.windowSize.width - player.spriteSize.width; // this is the right most position the player can be
    }
    else if (player.position.x + dx < 0) // the player is off the screen to the left
    {
        player.position.x = 0;
    }
    else
    {
        player.position.x += dx;
    }
}

void PlayerShoot(Player & player)
{
    if(player.missile.x == NOT_IN_PLAY || player.missile.y == NOT_IN_PLAY)
    {
        player.missile.y = player.position.y - 1; // one row above the player
        player.missile.x = player.position.x + player.spriteSize.width / 2;
    }
}

void DrawPlayer(const Player & player, const char * sprite[])
{
    CursesUtils::DrawSprite(player.position.x, player.position.y, sprite, player.spriteSize.height);
    
    if(player.missile.x != NOT_IN_PLAY)
    {
        CursesUtils::DrawCharacter(player.missile.x, player.missile.y, PLAYER_MISSILE_SPRITE);
    }
}

void UpdateMissile(Player & player)
{
    if(player.missile.y != NOT_IN_PLAY)
    {
        player.missile.y -= PLAYER_MISSILE_SPEED;
        
        if(player.missile.y < 0)
        {
            ResetMissile(player);
        }
    }
}

void InitShields(const Game & game, Shield shields[], int numberOfShields)
{
    // evenly spacing it out
    int firstPadding = ceil(float(game.windowSize.width - numberOfShields * SHIELD_SPRITE_WIDTH) / float(numberOfShields + 1));
    int xPadding = floor(float(game.windowSize.width - numberOfShields * SHIELD_SPRITE_WIDTH) / float(numberOfShields + 1));
    
    for(int i = 0; i < numberOfShields; i++)
    {
        Shield & shield = shields[i];
        shield.position.x = firstPadding + i * (SHIELD_SPRITE_WIDTH + xPadding);
        shield.position.y = game.windowSize.height - PLAYER_SPRITE_HEIGHT - 1 - SHIELD_SPRITE_HEIGHT - 2;
        
        for( int row = 0; row < SHIELD_SPRITE_HEIGHT; row++)
        {
            shield.sprite[row] = new char[SHIELD_SPRITE_WIDTH + 1];
            strcpy(shield.sprite[row], SHIELD_SPRITE[row]);
        }
    }
}

void CleanUpShields(Shield shields[], int numberOfShields)
{
    for(int i = 0; i < numberOfShields; i++)
    {
        Shield & shield = shields[i];
        
        for(int row = 0; row < SHIELD_SPRITE_HEIGHT; row++)
        {
            delete [] shield.sprite[row];
        }
    }
}

void DrawShields(const Shield shields[], int numberOfShields)
{
    for(int i = 0; i < numberOfShields; i++)
    {
        const Shield & shield = shields[i];
        
        CursesUtils::DrawSprite(shield.position.x, shield.position.y, (const char **) shield.sprite, SHIELD_SPRITE_HEIGHT);
    }
}

int IsCollision(const Position &projectile, const Shield shields[], int numberOfShields, Position &shieldCollisionPoint)
{
    shieldCollisionPoint.x = NOT_IN_PLAY;
    shieldCollisionPoint.y = NOT_IN_PLAY;
    
    if(projectile.y != NOT_IN_PLAY)
    {
        for(int i = 0; i < numberOfShields; i++)
        {
            const Shield & shield = shields[i];
            
            if(
                (projectile.x >= shield.position.x && projectile.x < shield.position.x + SHIELD_SPRITE_WIDTH)      // is it in line horizontally
                && (projectile.y >= shield.position.y && projectile.y < shield.position.y + SHIELD_SPRITE_HEIGHT)  // is it in line vertically
                && shield.sprite[projectile.y - shield.position.y][projectile.x - shield.position.x] != ' '        // does it collide with part of the shield
                )
            {
                // we collided
                shieldCollisionPoint.x = projectile.x - shield.position.x;
                shieldCollisionPoint.y = projectile.y - shield.position.y;
                return i;
            }
        }
    }
    
    return NOT_IN_PLAY;
}


void ResolveShieldCollision(Shield shields[], int shieldIndex, const Position & shieldCollisionPoint)
{
    shields[shieldIndex].sprite[shieldCollisionPoint.y][shieldCollisionPoint.x] = ' ';
}
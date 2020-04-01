//
// Created by Dmitry Petukhov on 29/03/2020.
//

#include <iostream>
#include "TextInvaders.h"
#include "CursesUtils.h"

using namespace std;

void InitGame(Game & game);
void InitPlayer(const Game & game, Player & player);
void ResetPlayer(const Game & game, Player & player);
void ResetMissile(Player & player);
int HandleInput(const Game & game, Player & player);
void UpdateGame(const Game & game, Player & player);
void DrawGame(const Game & game, const Player & player);
void MovePlayer(const Game & game, Player & player, int dx);

int main()
{
    Game game;
    Player player;
    
    CursesUtils::InitializeCurses(true);
    
    InitGame(game);
    InitPlayer(game, player);
    
    bool quit = false;
    char input;
    
    while(!quit)
    {
        input = HandleInput(game, player);
        if(input != 'q')
        {
            UpdateGame(game, player);
            CursesUtils::ClearScreen();
            DrawGame(game, player);
            CursesUtils::RefreshScreen();
        }
        else
        {
            quit = true;
        }
    }
    
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
    }
    return ' ';
}
void UpdateGame(const Game &game, Player &player)
{

}
void DrawGame(const Game &game, const Player &player)
{
    CursesUtils::DrawSprite(player.position.x, player.position.y, PLAYER_SPRITE, player.spriteSize.height);
    
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
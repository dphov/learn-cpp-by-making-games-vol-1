//
// Created by Dmitry Petukhov on 26/01/2020.
//

/*
 * Game: Battleship
 * The game is played on four 10x10 grids by 2 players, with each other player having 2 grids each.
 * The rows of the grid go from A to J in the rows and 1 to 10 in the columns. Each player will
 * arrange their ships on their respective ship board before the main game starts.
 * Each ship occupies a number of consecutive squares on the grid, arranged either horizontally
 * or vertically. The number of squares for each ship is determined by the type of the ship.
 * The ships cannot overlap.
 *
 * The ships are as follows:
 *
 * Ship type            Size
 * ------------------+---------
 * Aircraft carrier  |   5
 * Battleship        |   4
 * Cruiser           |   3
 * Destroyer         |   3
 * Submarine         |   2
 *
 * After the ships have been positioned, the game proceeds in a series of rounds. In each round,
 * each player takes a turn to announce a target in the opponent's grid which is to be shot at.
 * The opponent announces whether or not the square is occupied by a ship, and if it is a miss, the player
 * marks their guess board as a miss; if it is a hit, they mark it as a hit. This is to build up a picture
 * of the opponent's fleet. If the guess was a hit, the attacked player will mark their ship as hit in
 * the guessed location. That will end the turn.
 *
 * When all of the squares of a ship have been hit, the ship is sunk and there is output about
 * what ship was sunk. If all the player's ship have been sunk, the game is over and their opponent wins.
 *
 *
 * General:
 * -Ships
 * -Boards
 * -Players
 * -Guess (position on the board)
 *
 * Ships
 * -----
 * -5 types - listed above
 * -Have a size
 * -Has a position on the board (row between A - J, columns between 1 - 10)
 * -Orientation (either vertical or horizontal)
 * -Can be damaged in a specific spot
 *
 * Boards
 * ------
 * - 2 different boards - Ship boards (where you place all your ships), guess boards (your view of the opponent's board)
 * - Each position on the Guess board can be in 3 states - hit, miss, we haven't guessed the spot
 * - Board for ships - contain all the players ships at certain locations, we place markers on the spots where our
 *     ships have been hit
 *
 * Players
 * -------
 * - Name
 * - All the ships
 * - Guess board
 * - Ship board
 *
 * Guess
 * -----
 * - Position on the board
 * - Position has a row (A - J), columns (1 - 10)
 */

enum
{
    AIRCRAFT_CARRIER_SIZE = 5,
    BATTLESHIP_SIZE = 4,
    CRUISER_SIZE = 3,
    DESTROYER_SIZE = 3,
    SUBMARINE_SIZE = 2,

    BOARD_SIZE = 10,
    NUM_SHIPS = 5,
    PLAYER_NAME_SIZE = 8, // Player 1, Player 2
    MAX_SHIP_SIZE = AIRCRAFT_CARRIER_SIZE
};

enum ShipType
{
    ST_NONE = 0,
    ST_AIRCRAFT_CARRIER,
    ST_BATTLESHIP,
    ST_CRUISER,
    ST_DESTROYER,
    ST_SUBMARINE
};

enum ShipOrientationType
{
    SO_HORIZONTAL = 0,
    SO_VERTICAL
};

struct ShipPositionType
{
    int row;
    int col;
};

struct Ship
{
    ShipType shipType;
    int shipSize;
    ShipOrientationType orientation;
    ShipPositionType position;
};

struct GuessType
{
    GT_NONE = 0,
    GT_MISSED,
    GT_HIT
};

struct ShipPartType
{
    ShipType shipType;
    bool isHit;
};

struct Player
{
    char playerName[PLAYER_NAME_SIZE];
    Ship ships[NUM_SHIPS];
    GuessType guessBoard[BOARD_SIZE][BOARD_SIZE];
    ShipPartType shipBoard[BOARD_SIZE][BOARD_SIZE];
};

int main()
{
    return 0;
}
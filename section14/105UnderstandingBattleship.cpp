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
 * -2 different boards - Ship boards (where you place all your ships), guess boards (your view of the opponent's board)
 *
 *
 *
 */
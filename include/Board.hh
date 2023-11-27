#pragma once

#include "Coordinate.hh"
#include "Square.hh"
#include <map>
#include <vector>

/**
 * The most important class in the program.
 *
 * This class contains a map from the coordinates to the actual squares
 * that contain pieces.
 * It also has methods to accept moves from the command line, to move pieces
 * and check the game status.
 *
 * It is a singleton.
 */
class Board
{
public:
  static Board &Instance();

  Board(const Board &) = delete;
  Board(const Board &&) = delete;
  Board &operator=(const Board &) = delete;
  Board &operator=(const Board &&) = delete;

  /**
   * The default constructor.
   *
   * It initializes all 64 squares to an empty state.
   */
  void InitializeBoard();

  // TODO make this method constant (there are some problems with the iterator)
  /**
   * Print the state of the board from the white perspective.
   *
   * It displays visually to the screen the board using UNICODE characters
   *
   * @param[in] simplified wether to use simplified chars to print
   *  (useful if terminal doesn't support special chars)
   */
  void printBoard(const bool &simplified = false);

  // TODO make this method constant (there are some problems with the iterator)
  /**
   * Print the state of the board from the black perspective.
   *
   * It displays visually to the screen the board using UNICODE characters
   *
   * @param[in] simplified wether to use simplified chars to print
   *  (useful if terminal doesn't support special chars)
   */
  void printBoardReversed(const bool &simplified = false);

private:
  Board() {}

  std::map<Coordinate, Square> squaresMap;
};

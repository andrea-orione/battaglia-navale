#include "Board.hh"

#include <iostream>
#include <string>

using std::cout;
using std::endl;

Board &Board::Instance()
{
  static Board instance;

  return instance;
}

void Board::InitializeBoard()
{
  squaresMap = std::map<Coordinate, std::shared_ptr<Piece>>();

  for (int row = 1; row < 9; row++)
  {
    for (int column = 1; column < 9; column++)
    {
      squaresMap.insert(std::make_pair(Coordinate(column, row), nullptr));
    }
  }
}

// TODO make this method const
void Board::printBoard(bool simplified) const
{
  std::string top = (simplified) ? "---------------------------------" : "╔═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╗";
  std::string middle = (simplified) ? "|---|---|---|---|---|---|---|---|" : "╟───┼───┼───┼───┼───┼───┼───┼───╢";
  std::string bottom = (simplified) ? "---------------------------------" : "╚═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╝";
  std::string border = (simplified) ? "|" : "║";
  std::string separator = (simplified) ? "|" : "│";

  cout << "\n   " << top << "\n";
  for (int row = 8; row > 0; row--)
  {
    cout << " " << row << " " << border << " ";
    for (int column = 1; column < 9; column++)
    {
      auto piecePtr = squaresMap.find(Coordinate(column, row))->second;

      if (piecePtr == nullptr)
        cout << " ";
      else
        cout << piecePtr->toString(simplified);

      // Slightly inefficient but makes the code cleaner
      if (column != 8)
        cout << " " << separator << " ";
      else
        cout << " " << border;
    }
    if (row != 1)
      cout << "\n   " << middle << "\n";
    else
      cout << "\n   " << bottom << "\n";
  }
  cout << "     a   b   c   d   e   f   g   h\n\n";
}

// TODO make this method const
void Board::printBoardReversed(bool simplified) const
{
  std::string top = (simplified) ? "---------------------------------" : "╔═══╤═══╤═══╤═══╤═══╤═══╤═══╤═══╗";
  std::string middle = (simplified) ? "|---|---|---|---|---|---|---|---|" : "╟───┼───┼───┼───┼───┼───┼───┼───╢";
  std::string bottom = (simplified) ? "---------------------------------" : "╚═══╧═══╧═══╧═══╧═══╧═══╧═══╧═══╝";
  std::string border = (simplified) ? "|" : "║";
  std::string separator = (simplified) ? "|" : "│";

  cout << "\n   " << top << "\n";
  for (int row = 1; row < 9; row++)
  {
    cout << " " << row << " " << border << " ";
    for (int column = 8; column > 0; column--)
    {
      auto piecePtr = squaresMap.find(Coordinate(column, row))->second;

      if (piecePtr == nullptr)
        cout << " ";
      else
        cout << piecePtr->toString(simplified);

      // Slightly inefficient but makes the code cleaner
      if (column != 1)
        cout << " " << separator << " ";
      else
        cout << " " << border;
    }
    if (row != 8)
      cout << "\n   " << middle << "\n";
    else
      cout << "\n   " << bottom << "\n";
  }
  cout << "     h   g   f   e   d   c   b   a\n\n";
}

void Board::AddPiece(std::pair<Coordinate, std::shared_ptr<Piece>> pair)
{
  squaresMap[pair.first] = pair.second;
}

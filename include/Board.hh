#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "Coordinate.hh"
#include "Piece.hh"

// TODO Delete testing functions (printWhitePieces() and printBlackPieces())
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

  Board(const Board &) = delete;             // delete copy constructor
  Board(const Board &&) = delete;            // delete move constructor
  Board &operator=(const Board &) = delete;  // delete assignment operator
  Board &operator=(const Board &&) = delete; // delete move assignment operator

  // void InitializeBoard();

  void PrintWhiteBoard(bool simplified) const;
  void PrintBlackBoard(bool simplified) const;

  void UpdateSquare(std::pair<Coordinate, std::shared_ptr<Piece>> &&square) noexcept;
  void UpdatePiecesVector();
  void AddKings(const Coordinate whiteKingPosition, const Coordinate blackKingPosition);

  bool IsSquareAttacked(const Coordinate square, const PieceColor attackerColor) const;
  void NormalMove(std::shared_ptr<Piece> &&movingPiece, const Coordinate endingPosition);

  std::shared_ptr<Piece> GetPiece(const Coordinate position) const;

  void ClearBoard();
  void ResetMoveNumber() { moveNumber = 0; }
  void IncrementMoveNumber(const int increment = 1) { moveNumber += increment; }
  int GetMoveNumber() const { return moveNumber; }

  std::string GetWhiteCapturedPieces(const bool literal = false) const;
  std::string GetBlackCapturedPieces(const bool literal = false) const;

  void printWhitePieces() const;
  void printBlackPieces() const;

private:
  Board(); // private constructor

  void Castling(std::shared_ptr<Piece> &&king, const Coordinate kingEndingPosition);
  void EnPassant(std::shared_ptr<Piece> &&pawn, const Coordinate pawnEndingPosition);

  // Map defining the squares as {coordinate : pointer to piece}.
  std::map<Coordinate, std::shared_ptr<Piece>> squaresMap;

  // Vector with the pointers to the white pieces on the board.
  std::vector<std::shared_ptr<Piece>> whitePieces;
  // Vector with the pointers to the black pieces on the board.
  std::vector<std::shared_ptr<Piece>> blackPieces;
  // Vector with the pointers to the white pieces captured.
  std::vector<std::shared_ptr<Piece>> whiteCapturedPieces;
  // Vector with the pointers to the black pieces captured.
  std::vector<std::shared_ptr<Piece>> blackCapturedPieces;

  // The number of moves done.
  int moveNumber;

  // Pointer to the white king.
  std::shared_ptr<Piece> whiteKing;
  // Pointer to the black king.
  std::shared_ptr<Piece> blackKing;
};

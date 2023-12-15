#include "Utils.hh"
#include "Piece.hh"

PieceColor operator!(const PieceColor &oldColor)
{
  return (oldColor == PieceColor::WHITE) ? PieceColor::BLACK : PieceColor::WHITE;
}

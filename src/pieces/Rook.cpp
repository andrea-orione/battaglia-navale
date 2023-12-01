#include "Rook.hh"

Rook::Rook(PieceColor pColor): color(pColor)
{
  switch (color)
  {
  case PieceColor::WHITE:
    character = "♜";
    break;
  case PieceColor::BLACK:
    character = "♖";
    break;
  default:
    break;
  }

  switch (color)
  {
  case PieceColor::WHITE:
    literalCharacter = 'R';
    break;
  case PieceColor::BLACK:
    literalCharacter = 'r';
    break;
  default:
    break;
  }
}

std::string Rook::toString(bool literal) const
{
  if (literal) return std::to_string(literalCharacter);
  return character;
}

std::vector<Coordinate> Rook::listValidCoordinate() const
{
    return std::vector<Coordinate>();
}
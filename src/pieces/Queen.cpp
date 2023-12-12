#include "Queen.hh"

#include <memory>

#include "Board.hh"

Queen::Queen(PieceColor pColor, Coordinate pPosition)
{
  color = pColor;
  position = pPosition;
  switch (color)
  {
  case PieceColor::WHITE:
    character = "♛";
    literalCharacter = 'Q';
    break;
  case PieceColor::BLACK:
    character = "♕";
    literalCharacter = 'q';
    break;
  default:
    break;
  }
}

std::string Queen::toString(bool literal) const
{
  if (literal)
    return std::string(1, literalCharacter);
  return character;
}

bool Queen::isMoveValid(const Coordinate &startingPosition, const Coordinate &endingPosition) const
{
  int xDistance = endingPosition.getX() - startingPosition.getX();
  int yDistance = endingPosition.getY() - startingPosition.getY();

  // geometric check
  if (abs(xDistance) != abs(yDistance) || (xDistance != 0 && yDistance != 0))
    return false;

  // determine direction
  int xDirection = (xDistance == 0) ? 0 : xDistance / abs(xDistance);
  int yDirection = (yDistance == 0) ? 0 : yDistance / abs(yDistance);
  Movement baseMove = Movement();

  // determine if the move is valid valid
  Board &board = Board::Instance();
  std::shared_ptr<Piece> mainPiece = board.getPiece(startingPosition);

  for (int i = 0; i < xDistance; i++)
  {
    const Coordinate newPosition = startingPosition + baseMove * i;
    std::shared_ptr<Piece> newPiece = board.getPiece(newPosition);

    if (newPiece != nullptr)
    {
      if (newPosition == endingPosition && newPiece->getColor() != mainPiece->getColor())
        return true;

      return false;
    }
  }
  return true;
}
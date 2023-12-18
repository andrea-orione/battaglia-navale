#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

#include "Movement.hh"

// TODO Delete DEPRECATED methods
/**
 * The coordinate system on the board.
 *
 * It is just a pair of two integers constrained between 1 and 8 (included).
 */
class Coordinate
{
public:
  Coordinate(int newX = 1, int newY = 1);
  Coordinate(char literalNewX, int newY);
  Coordinate(std::string_view literalExpression);
  Coordinate(const Coordinate &newCoordinate);
  Coordinate &operator=(const Coordinate &newCoordinate);

  Coordinate &setX(int newX);
  Coordinate &setY(int newY);
  int getX() const { return x; }
  int getY() const { return y; }

  bool operator<(const Coordinate &other) const;
  bool operator>(const Coordinate &other) const;
  bool operator==(const Coordinate &other) const;
  bool operator!=(const Coordinate &other) const;
  bool operator<=(const Coordinate &other) const;
  bool operator>=(const Coordinate &other) const;

  Coordinate &operator+(const Movement &movement);
  Coordinate &operator+=(const Movement &movement);

  int squaredDistance(const Coordinate other) const;

  std::string toString() const;

private:
  static const std::string literalChars;
  int x;
  int y;
};

#pragma once

#include <memory>
#include <string>
#include <regex>
#include <fstream>

#include "Piece.hh"

/**
 * A class for managing the creation of the pieces,
 * the board and the user IO.
 */
class GameManager
{
public:
  GameManager();
  ~GameManager() = default;

  static std::shared_ptr<Piece> makePiece(char pieceChar, const Coordinate pPosition, const bool hasRookMoved = true);

  void startGame();
  void gameLoop();

private:
  static std::regex regexRuleNormal;
  static std::regex regexRulePromotion;

  PieceColor activePlayerColor;
  bool gameFinished;
  bool simplified;

  std::fstream welcomeFile;
  std::fstream helpFile;
  std::fstream settingsFile;

  void loadFenPosition(std::string &&fenString) const;
  void InitializeStartingBoard() const;
  void helpUser();
  void userSettings();
  void getUserMove();
  void killGame() const;

#ifdef _WIN32
  const char *welcomeFilePath = "..\\utils\\welcome.txt";
  const char *helpFilePath = "..\\utils\\help.txt";
  const char *settingsFilePath = "..\\utils\\settings.txt";
#else
  const char *welcomeFilePath = "../utils/welcome.txt";
  const char *helpFilePath = "../utils/help.txt";
  const char *settingsFilePath = "../utils/settings.txt";
#endif
};

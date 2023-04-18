#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <functional>
#include "Piece.h"
#include "Utilities.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class Board {
public:
	Board(const std::string& boardString);
	int runCommand(const std::string& command);


private:
	//private functions
	Board(const Board& other);
	bool isValidInput(const std::string& input) const;
	bool isPathClear(const Place& src, const Place& dst) const;
	bool isKingUnderAttack(const PieceColor& color) const;
	void movePiece(const Place& src, const Place& dst);
	std::shared_ptr<Piece> createPiece(const char piece) const;

	// private members
	std::vector<std::pair<std::shared_ptr<Piece>, Place>> m_board;
	PieceColor m_turn = PieceColor::WHITE;
};
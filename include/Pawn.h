#pragma once
#include "Piece.h"



class Pawn : public Piece {
public:
	Pawn(const PieceColor color);
	~Pawn() override = default;
	std::vector<Place> getValidMoves(const Place& source, const bool emptyDst) const override;
	std::shared_ptr<Piece> clone() const override;

};
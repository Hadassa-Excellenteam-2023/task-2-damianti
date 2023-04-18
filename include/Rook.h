#pragma once
#include "Piece.h"

class Rook : public virtual Piece {
public:
	Rook(const PieceColor color);
	~Rook() override = default;
	std::vector<Place> getValidMoves(const Place& source, const bool emptyDst) const override;
	std::shared_ptr<Piece> clone() const override;
};
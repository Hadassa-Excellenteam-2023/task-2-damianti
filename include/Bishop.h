#pragma once
#include "Piece.h"


class Bishop : public virtual Piece {
public:
	Bishop(const PieceColor color);
	~Bishop() override = default;
	std::vector<Place> getValidMoves(const Place& source, const bool emptyDst) const override;
	std::shared_ptr<Piece> clone() const override;
};
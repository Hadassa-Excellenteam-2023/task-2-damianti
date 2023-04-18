#pragma once
#include "Piece.h"


class King : public Piece {
public:
	King(const PieceColor color);
	~King() override = default;
	std::vector<Place> getValidMoves(const Place& source, const bool emptyDst) const override;
	std::shared_ptr<Piece> clone() const override;
};
#pragma once
#include "Piece.h"


class Knight : public Piece {
public:
	Knight(const PieceColor color);
	~Knight() override = default;
	std::vector<Place> getValidMoves(const Place& source, const bool emptyDst) const override;
	std::shared_ptr<Piece> clone() const override;
};


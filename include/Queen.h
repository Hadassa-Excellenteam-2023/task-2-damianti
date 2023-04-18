#pragma once
#include "Rook.h"
#include "Bishop.h"

class Queen : public Rook, public Bishop {
public:
	Queen(const PieceColor color);
	~Queen() override = default;
	std::vector<Place> getValidMoves(const Place& source, const bool emptyDst) const override;
	std::shared_ptr<Piece> clone() const override;
};
#pragma once
#include <iostream>
#include <string>
#include "Utilities.h"



class Piece {

public:
    Piece(const PieceColor color);
    virtual ~Piece() = default;
    virtual std::vector<Place> getValidMoves(const Place& source, const bool emptyDst) const = 0;
    virtual std::shared_ptr<Piece> clone() const = 0;
    PieceColor getColor() const;

protected:
    PieceColor m_color;
};
#pragma once
#include "Piece.h"



/**
* @brief Constructs a new Piece object with a specified color.
* @param color The color of the Piece (PieceColor::WHITE or PieceColor::BLACK).
*/
Piece::Piece(const PieceColor color)
	:m_color(color)
{}

PieceColor Piece::getColor() const
{
	return m_color;
}

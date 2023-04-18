#include "Queen.h"

/**
* @brief Constructs a new Queen object with a specified color.
* @param color The color of the Queen (PieceColor::WHITE or PieceColor::BLACK).
*/
Queen::Queen(const PieceColor color)
	:Piece(color), Rook(color), Bishop(color)
{
}
/**
* @brief Generates a list of valid moves for the queen from a given source position.
* @param source The source position of the queen.
* @param emptyDst True if the destination is empty, false otherwise (not used for Queen, only for Pawn).
* @return A vector of valid destination positions.
*/
std::vector<Place> Queen::getValidMoves(const Place& source, const bool emptyDst) const
{
	auto moves = Bishop::getValidMoves(source, emptyDst);
	auto rookMoves = Rook::getValidMoves(source, emptyDst);
	moves.insert(moves.end(), rookMoves.begin(), rookMoves.end());

	return moves;

}
/**
* @brief Creates a deep copy of the Queen object.
* @return A shared pointer to the new Queen object.
*/
std::shared_ptr<Piece> Queen::clone() const
{
	return std::make_shared<Queen>(*this);
}

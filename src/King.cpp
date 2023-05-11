#include "King.h"

/**
	 * @brief Constructs a new King object with a specified color.
	 * @param color The color of the King (PieceColor::WHITE or PieceColor::BLACK).
	 */
King::King(const PieceColor color)
	:Piece(color)
{
}


/**
* @brief Generates a list of valid moves for the king from a given source position.
* @param source The source position of the king.
* @param emptyDst True if the destination is empty, false otherwise (not used for King, only for Pawn).
* @return A vector of valid destination positions.
*/
std::vector<Place> King::getValidMoves(const Place& source, const bool  /*emptyDst*/) const
{
	auto moves = std::vector<Place>();

	if (source.m_row + 1 < BOARD_SIZE)
		moves.push_back({ source.m_row + 1, source.m_col });
	if (source.m_row - 1 >= 0)
		moves.push_back({ source.m_row - 1, source.m_col });
	if (source.m_col + 1 < BOARD_SIZE)
		moves.push_back({ source.m_row, source.m_col + 1 });
	if (source.m_col - 1 >= 0)
		moves.push_back({ source.m_row , source.m_col - 1 });

	//diagonals
	if (source.m_row + 1 < BOARD_SIZE && source.m_col + 1 < BOARD_SIZE)
		moves.push_back({ source.m_row + 1, source.m_col + 1});
	if (source.m_row + 1 < BOARD_SIZE && source.m_col - 1 >= 0)
		moves.push_back({ source.m_row + 1, source.m_col - 1});
	if (source.m_row - 1 >= 0 && source.m_col + 1 < BOARD_SIZE)
		moves.push_back({ source.m_row - 1, source.m_col + 1 });
	if (source.m_row - 1 >= 0 && source.m_col - 1 >= 0)
		moves.push_back({ source.m_row - 1, source.m_col - 1 });


	return moves;

}
/**
* @brief Creates a deep copy of the King object.
* @return A shared pointer to the new King object.
*/
std::shared_ptr<Piece> King::clone() const
{
	return std::make_shared<King>(*this);
}

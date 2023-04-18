#include "Bishop.h"
/**
	 * @brief Constructs a new Bishop object with a specified color.
	 * @param color The color of the bishop (PieceColor::WHITE or PieceColor::BLACK).
	 */
Bishop::Bishop(const PieceColor color)
	:Piece(color)
{
}
/**
* @brief Generates a list of valid moves for the bishop from a given source position.
* @param source The source position of the bishop.
* @param emptyDst True if the destination is empty, false otherwise (not used for Bishop, only for Pawn).
* @return A vector of valid destination positions.
*/
std::vector<Place> Bishop::getValidMoves(const Place& source, const bool  /*emptyDst*/) const
{
	auto moves = std::vector<Place>();
	for (int move = 1; move < BOARD_SIZE; ++move) {
		if (source.m_row + move < BOARD_SIZE && source.m_col + move < BOARD_SIZE)
			moves.push_back({ source.m_row + move, source.m_col + move });

		if (source.m_row + move < BOARD_SIZE && source.m_col - move >= 0)
			moves.push_back({ source.m_row + move, source.m_col - move });

		if (source.m_row - move >= 0 && source.m_col + move < BOARD_SIZE)
			moves.push_back({ source.m_row - move, source.m_col + move });

		if (source.m_row - move >= 0 && source.m_col - move >= 0)
		if (source.m_row - move >= 0 && source.m_col - move >= 0)
			moves.push_back({ source.m_row - move, source.m_col - move });

	}

	return moves;
}
/**
* @brief Creates a deep copy of the Bishop object.
* @return A shared pointer to the new Bishop object.
*/
std::shared_ptr<Piece> Bishop::clone() const
{
	return std::make_shared<Bishop>(*this);
}

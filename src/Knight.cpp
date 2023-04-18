#include "Knight.h"

/**
* @brief Constructs a new Knight object with a specified color.
* @param color The color of the Knight (PieceColor::WHITE or PieceColor::BLACK).
*/
Knight::Knight(const PieceColor color)
	:Piece(color)
{
}

/**
* @brief Generates a list of valid moves for the knight from a given source position.
* @param source The source position of the bishop.
* @param emptyDst True if the destination is empty, false otherwise (not used for Knight, only for Pawn).
* @return A vector of valid destination positions.
*/
std::vector<Place> Knight::getValidMoves(const Place& source, const bool  /*emptyDst*/) const
{
    auto moves = std::vector<Place>();

    // Calculate all 8 possible moves for a knight
    int row = source.m_row;
    int col = source.m_col;
    if (row + 2 < BOARD_SIZE && col + 1 < BOARD_SIZE)
        moves.push_back({ row + 2, col + 1 });
    if (row + 2 < BOARD_SIZE && col - 1 >= 0)
        moves.push_back({ row + 2, col - 1 });
    if (row - 2 >= 0 && col + 1 < BOARD_SIZE)
        moves.push_back({ row - 2, col + 1 });
    if (row - 2 >= 0 && col - 1 >= 0)
        moves.push_back({ row - 2, col - 1 });
    if (row + 1 < BOARD_SIZE && col + 2 < BOARD_SIZE)
        moves.push_back({ row + 1, col + 2 });
    if (row + 1 < BOARD_SIZE && col - 2 >= 0)
        moves.push_back({ row + 1, col - 2 });
    if (row - 1 >= 0 && col + 2 < BOARD_SIZE)
        moves.push_back({ row - 1, col + 2 });
    if (row - 1 >= 0 && col - 2 >= 0)
        moves.push_back({ row - 1, col - 2 });

    return moves;
}
/**
* @brief Creates a deep copy of the Knight object.
* @return A shared pointer to the new Knight object.
*/
std::shared_ptr<Piece> Knight::clone() const
{
    return std::make_shared<Knight>(*this);
}

#include "Rook.h"

/**
* @brief Constructs a new Rook object with a specified color.
* @param color The color of the Rook (PieceColor::WHITE or PieceColor::BLACK).
*/
Rook::Rook(const PieceColor color)
	:Piece(color)
{
}

/**
* @brief Generates a list of valid moves for the rook from a given source position.
* @param source The source position of the rook.
* @param emptyDst True if the destination is empty, false otherwise (not used for Rook, only for Pawn).
* @return A vector of valid destination positions.
*/
std::vector<Place> Rook::getValidMoves(const Place& source, const bool  /*emptyDst*/) const {

    std::vector<Place> moves;
    for (int row = 0; row < BOARD_SIZE; row++) {
        if (row != source.m_row) {
            moves.push_back({ row, source.m_col });
        }
    }
    for (int col = 0; col < BOARD_SIZE; col++) {
        if (col != source.m_col) {
            moves.push_back({ source.m_row, col });
        }
    }
    return moves;
}
/**
* @brief Creates a deep copy of the Rook object.
* @return A shared pointer to the new Rook object.
*/
std::shared_ptr<Piece> Rook::clone() const
{
    return std::make_shared<Rook>(*this);
}

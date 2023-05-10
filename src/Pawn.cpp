#include "Pawn.h"

/**
* @brief Constructs a new Pawn object with a specified color.
* @param color The color of the Pawn (PieceColor::WHITE or PieceColor::BLACK).
*/
Pawn::Pawn(const PieceColor color)
	:Piece(color)
{
}
/**
* @brief Generates a list of valid moves for the pawn from a given source position.
* @param source The source position of the pawn.
* @param emptyDst True if the destination is empty, false otherwise (this is only used in Pawn).
* @return A vector of valid destination positions.
*/
std::vector<Place> Pawn::getValidMoves(const Place& source, const bool emptyDst) const
{
    std::vector<Place> moves;

    int direction = (getColor() == PieceColor::WHITE) ? 1 : -1;
    int startRow = (getColor() == PieceColor::WHITE) ? 1 : 6;

    // One square forward
    if (emptyDst) {
        Place oneForward = { source.m_row + direction, source.m_col };
        moves.push_back(oneForward);

        // Two squares forward
        if (source.m_row == startRow) {
            Place twoForward = { source.m_row + 2 * direction, source.m_col };
            moves.push_back(twoForward);
        }
    }

    else {
        // Capture diagonally forward
        if (source.m_col > 0) {
            Place captureLeft = { source.m_row + direction, source.m_col - 1 };
            moves.push_back(captureLeft);
        }
        if (source.m_col < BOARD_SIZE - 1) {
            Place captureRight = { source.m_row + direction, source.m_col + 1 };
            moves.push_back(captureRight);
        }

    }

    return moves;
}
/**
* @brief Creates a deep copy of the Pawn object.
* @return A shared pointer to the new Pawn object.
*/
std::shared_ptr<Piece> Pawn::clone() const
{
    return std::make_shared<Pawn>(*this);
}


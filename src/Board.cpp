#include "Board.h"
#include <typeindex>


/**
 * @brief Constructor that initializes the board with a given string representation.
 * @param boardString The string representation of the initial board state.
 */
Board::Board(const std::string& boardString)
{
    for (size_t i = 0; i < boardString.length(); i++) {
        auto piece = createPiece(boardString[i]);
        if (piece)
            m_board.push_back({ piece, Place(i) });
    }
}

/**
 * @brief Copy constructor that creates a deep copy of the given board.
 * @param other The board to copy.
 */
Board::Board(const Board& other) {
    for (const auto& pair : other.m_board) {
        m_board.push_back({ pair.first->clone(), pair.second });
    }
    m_turn = other.m_turn;
}

/**
 * @brief Creates a Piece object based on the given character.
 * @param piece The character representing the piece to create.
 * @return A shared pointer to the created Piece object, or nullptr if the character is not recognized.
 */
std::shared_ptr<Piece> Board::createPiece(const char piece) const
{
    static std::map<char, std::function<std::shared_ptr<Piece>()>> piece_map = {
        {'P', []() { return std::make_shared<Pawn>(PieceColor::WHITE); }},
        {'p', []() { return std::make_shared<Pawn>(PieceColor::BLACK); }},
        {'R', []() { return std::make_shared<Rook>(PieceColor::WHITE); }},
        {'r', []() { return std::make_shared<Rook>(PieceColor::BLACK); }},
        {'N', []() { return std::make_shared<Knight>(PieceColor::WHITE); }},
        {'n', []() { return std::make_shared<Knight>(PieceColor::BLACK); }},
        {'B', []() { return std::make_shared<Bishop>(PieceColor::WHITE); }},
        {'b', []() { return std::make_shared<Bishop>(PieceColor::BLACK); }},
        {'Q', []() { return std::make_shared<Queen>(PieceColor::WHITE); }},
        {'q', []() { return std::make_shared<Queen>(PieceColor::BLACK); }},
        {'K', []() { return std::make_shared<King>(PieceColor::WHITE); }},
        {'k', []() { return std::make_shared<King>(PieceColor::BLACK); }}
    };

    auto it = piece_map.find(piece);
    if (it != piece_map.end()) {
        auto aPiece = it->second();
        return aPiece;
    }

    return nullptr;
}

/**
 * @brief Executes the given command string, moving a piece from one position to another.
 * @param command The command string, containing the source and destination positions.
 * @return An integer code representing the result of the move (e.g., illegal move, check, etc.).
 */
int Board::runCommand(const std::string& command)
{
    if (!isValidInput(command))
        return 11;
    
    Place src = { command[0] - 'a', command[1] - '1' };
    Place dst = { command[2] - 'a', command[3] - '1' };

    auto itSrc = std::find_if(m_board.begin(), m_board.end(),
        [&](const auto& p) {return p.second == src; });
    auto itDst = std::find_if(m_board.begin(), m_board.end(),
        [&](const auto& p) {return p.second == dst; });

    // checking if there is not piece at the source  
    if (itSrc == m_board.end())
        return 11;
    
    // checking if src color is the one who has to play
    else if (itSrc->first->getColor() != m_turn)
        return 12;

    // checking if dst color is not the same as the one who is playing
    if (itDst != m_board.end() && itDst->first->getColor() == m_turn)
        return 13;

    bool emptyDst = itDst == m_board.end() ? true : false;

    // emptyDst only serves for Pawn
    auto validMoves = itSrc->first->getValidMoves(src, emptyDst);

    //checking if dst is in valid moves. Also checking if the path is clear (only if the moving piece is not a Knight)
    if (std::find(validMoves.begin(), validMoves.end(), dst) == validMoves.end() ||
        ((typeid(*itSrc->first) != typeid(Knight)) && !isPathClear(src, dst))) {
        return 21;
    }
    
    //checking for a check that prevent moving a piece
    Board tempBoard(*this);
    tempBoard.movePiece(src, dst);
    if (tempBoard.isKingUnderAttack(m_turn)) {
        return 31;
    }

    //from here, the move is legal!!
    movePiece(src, dst);
    int ret;
    if (isKingUnderAttack(m_turn == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE))
        ret = 41;
    
    else ret = 42;

    //switching turn
    m_turn = m_turn == PieceColor::WHITE ? PieceColor::BLACK : PieceColor::WHITE;
    
    return ret;

}

/**
 * @brief Checks if the path between the source and destination positions is clear (i.e., unoccupied).
 * @param src The source position.
 * @param dst The destination position.
 * @return true if the path is clear, false otherwise.
 */
bool Board::isPathClear(const Place& src, const Place& dst) const
{
    int dx = dst.m_col - src.m_col;
    int dy = dst.m_row - src.m_row;

    // calculate the direction of the move
    int dxSign = dx == 0 ? 0 : (dx > 0 ? 1 : -1);
    int dySign = dy == 0 ? 0 : (dy > 0 ? 1 : -1);

    // check if the move is diagonal or horizontal/vertical
    bool diagonal = abs(dx) == abs(dy);
    bool straight = dx == 0 || dy == 0;

    if (!diagonal && !straight)
        return false;  // invalid move

    // check if there are pieces in the way
    int steps = diagonal ? abs(dx) : dx != 0 ? abs(dx) : abs(dy);

    Place curr = src;
    for (int i = 1; i < steps; i++)
    {
        curr.m_row += dySign;
        curr.m_col += dxSign;
        auto it = std::find_if(m_board.begin(), m_board.end(),
            [&](const auto& p) {return p.second == curr; });
        if (it != m_board.end())
            return false;  // there is a piece in the way
    }

    return true;  // path is clear
}


/**
 * @brief Validates the given command string.
 * @param input The command string to validate.
 * @return true if the command string is valid, false otherwise.
 */
bool Board::isValidInput(const std::string& input) const {
    if (input.length() != 4)
        return false;
    
    if (input[0] < 'a' || input[0] > 'h' || input[2] < 'a' || input[2] > 'h')
        return false;
    
    if (input[1] < '1' || input[1] > '8' || input[3] < '1' || input[3] > '8')
        return false;
   
    return true;
}


/**
 * @brief Moves a piece from the source to the destination position.
 * @param src The source position.
 * @param dst The destination position.
 */
void Board::movePiece(const Place& src, const Place& dst) {

    auto itSrc = std::find_if(m_board.begin(), m_board.end(),
        [&](const auto& p) { return p.second == src; });
    auto itDst = std::find_if(m_board.begin(), m_board.end(),
        [&](const auto& p) { return p.second == dst; });

    itSrc->second = dst;
    if (itDst != m_board.end())
        m_board.erase(itDst);
}

/**
 * @brief Checks if the king of the given color is under attack.
 * @param color The color of the king to check.
 * @return true if the king is under attack, false otherwise.
 */
bool Board::isKingUnderAttack(const PieceColor& color) const {
    //getting the place of the king
    Place kingPlace;
    for (const auto& p : m_board) {
        if (typeid(*p.first) == typeid(King) && p.first->getColor() == color) {
            kingPlace = p.second;
            break;
        }
    }
    //checking if someone can move to the place where the king is
    for (const auto& p : m_board) {
        if (p.first->getColor() != color) {
            auto validMoves = p.first->getValidMoves(p.second, true);

            if (std::find(validMoves.begin(), validMoves.end(), kingPlace) != validMoves.end() &&
                (typeid(*p.first) == typeid(Knight) || isPathClear(p.second, kingPlace))) {
                return true;
            }
        }
    }

    return false;
}
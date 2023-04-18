#pragma once
#include <vector>


enum class PieceColor {
    BLACK,
    WHITE
};

struct Place {
    Place() = default;
    Place(size_t index) : m_row(static_cast<int>(index / 8)), m_col(static_cast<int>(index % 8)) {}
    Place(const int row, const int col) : m_row(row), m_col(col) {}
    
    bool operator==(const Place& other) const {
        return m_row == other.m_row && m_col == other.m_col;
    }

    int m_row;
    int m_col;
};


const int BOARD_SIZE = 8;
//job done

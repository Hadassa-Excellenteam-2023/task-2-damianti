# Chess

This project is a simple Chess game implemented in C++. It provides a basic text-based interface for playing Chess and handles the game logic, including piece movement, checks, and captures. The game utilizes object-oriented programming concepts, including inheritance and polymorphism, to manage the different Chess pieces and their valid moves.

## Features

### Board
- Initialize board from a given string representation
- Execute a move command
- Check if a path between two positions is clear
- Validate input commands
- Create piece objects based on a given character
- Move a piece from one position to another
- Check if a king of a given color is under attack

### Pieces
- Pawn, Rook, Knight, Bishop, Queen, and King classes
- Each class inherits from the abstract `Piece` class
- Each class provides a list of valid moves based on the current position and game state
- Clone method for creating deep copies of pieces

## How to Build

1. Clone the repository or download the source code.
2. Compile the source code using a C++ compiler with C++11 support.
3. Run the compiled executable file.

## Usage

Include the `Board.h` header file and other required header files for Chess pieces in your project. Create an instance of the `Board` class and use its methods to interact with the game state.

Refer to the `main.cpp` file for example usage of the classes and their functionalities.

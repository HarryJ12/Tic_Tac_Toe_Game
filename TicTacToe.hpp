#pragma once

#include <map>
#include <array>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class TicTacToe: public Drawable {
 public:
    enum Marker { Empty, Cross, Naught }; // Possible states of a board cell

    // Initializes the game state, loads textures, sets the starting turn, and clears the board.
    TicTacToe();

    // Returns the size of the game window based on tile size and board dimensions.
    Vector2u windowSize() const;
    
    // Handles a mouse click by converting the click to a board position. Places a mark if valid, switches turns, 
    // and prevents moves once a winner has been identified. Takes in pt Screen coordinates of the mouse click and 
    // returns true if a move was made, false otherwise.
    bool onClick(Vector2i pt);

 protected:
   // Checks the board for a winning condition by evaluating all rows, columns, and both diagonals.
   // Returns true if either player has won, false otherwise.
    bool checkBoard() const;

    // Draws the current board state to the window. Takes in a window render target to draw to and the render states.
    void draw(RenderTarget&, RenderStates) const override;

 private:
   std::map<Marker, Texture> _textures;   // Texture lookup for each marker type (Empty, Naught, Cross)
   array<Marker, 9> _board;               // 3×3 board storing the current marker in each cell
   Vector2u _tileSize;                    // Pixel dimensions of a single tile image
   Marker _turn;                          // Whose turn it is (Cross or Naught)
};

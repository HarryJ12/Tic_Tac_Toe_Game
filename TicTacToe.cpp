#include "TicTacToe.hpp"

const size_t numRows = 3;
const size_t numCells = numRows * numRows;

TicTacToe::TicTacToe():
    _turn(Cross)
{
     _textures[Empty] = Texture("images/letter.png");
     _textures[Naught] = Texture("images/letter_O.png");
     _textures[Cross] = Texture("images/letter_X.png");
     _tileSize = _textures[Empty].getSize();
     for (auto& tile : _board) {
         tile = Empty;
     }

}

Vector2u TicTacToe::windowSize() const {
    return _tileSize * static_cast<unsigned int>(numRows);
}

bool TicTacToe::onClick(Vector2i pt) {
      if (checkBoard()) {
        return false;
      }
      Vector2u pos = Vector2u(pt);
      pos = pos.componentWiseDiv(_tileSize);
      size_t i = pos.y * numRows + pos.x;
      if (_board[i] == Empty) {
        _board[i] = _turn; 
        _turn = _turn == Cross ? Naught : Cross;
        return true;
      } else {
        return false; 
     }
}

bool TicTacToe::checkBoard() const {
    // Rows
    for (size_t y = 0; y < numRows; y++) {
        bool isNaught = true;
        bool isCross = true;
        for (size_t x = 0; x < numRows; x++) {
            size_t i = x + y * numRows;
            switch(_board[i]) {
                case Empty:
                    isNaught = false;
                    isCross = false;
                    break;
                case Naught:
                    isCross = false;
                    break;
                case Cross:
                    isNaught = false;
                    break;
            }
        } 
        if (isNaught || isCross) {
            return true;
        }
    }   
    // Columns
    for (size_t x = 0; x < numRows; x++) {
        bool isNaught = true;
        bool isCross = true;
        for (size_t y = 0; y < numRows; y++) {
            size_t i = x + y * numRows;
            switch(_board[i]) {
                case Empty:
                    isNaught = false;
                    isCross = false;
                    break;
                case Naught:
                    isCross = false;
                    break;
                case Cross:
                    isNaught = false;
                    break;
            }
        } 
        if (isNaught || isCross) {
            return true;
        }
    }   
    // Diagonal (top-left to bottom-right)
    bool isNaught = true;
    bool isCross = true;
    for (size_t y = 0; y < numRows; y++) {
        size_t i = y + y * numRows;
        switch(_board[i]) {
            case Empty:
                isNaught = false;
                isCross = false;
                break;
            case Naught:
                isCross = false;
                break;
            case Cross:
                isNaught = false;
                break;
        }
    }
    if (isNaught || isCross) {
        return true;
    }
    // Diagonal (top-right to bottom-left)
    isNaught = true;
    isCross = true;
    for (size_t y = 0; y < numRows; y++) {
        size_t i = 2 + -y + y * numRows;
        switch(_board[i]) {
            case Empty:
                isNaught = false;
                isCross = false;
                break;
            case Naught:
                isCross = false;
                break;
            case Cross:
                isNaught = false;
                break;
        }
    }
    if (isNaught || isCross) {
        return true;
    }

    return false;
}

void TicTacToe::draw(RenderTarget& window, RenderStates states) const {
    for (size_t i = 0; i < numCells; i++) {
        float x = _tileSize.x * (i % numRows);
        float y = _tileSize.x * (i / numRows);
        Sprite tile(_textures.at(_board[i]));
        tile.setPosition({x,y});
        window.draw(tile, states);
    }
}

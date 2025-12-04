#include <SFML/Graphics.hpp>
#include "TicTacToe.hpp"

using namespace std;

int main() {
    // Create the game logic object
    TicTacToe game;
    
    // Open an SFML window with the size required by the game
    RenderWindow window(VideoMode(game.windowSize()), "Tic-Tac-Toe!");

    // Put the window at the top-left of the screen
    window.setPosition({0, 0});

    // Window that runs until explicitly closed
    while (window.isOpen())
    {
        // Process events (mouse clicks, close events, etc.)
        while (const optional event = window.pollEvent())
        {
            // User clicked the window's X to close it
            if (event->is<Event::Closed>()) {
                window.close();
            }

            // Check for a mouse button press
            auto mouse = event->getIf<Event::MouseButtonPressed>();
            if (mouse) {
                // Pass the click position to the game logic
                game.onClick(mouse->position);
            }
        }

        // Clear the screen for a new frame
        window.clear();

        // Ask the game to draw the frame
        window.draw(game);

        // Push the rendered frame to the screen
        window.display();
    }
}

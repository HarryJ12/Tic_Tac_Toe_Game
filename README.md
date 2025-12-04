Tic-Tac-Toe game built with SFML in C++ that renders a fully interactive 3×3 board and handles all input, drawing, and game logic.
Mouse clicks map directly to board cells, turns alternate automatically, and the system locks further moves once a win condition appears.

Internally, the board is stored in a fixed-size array with an enum-based marker system, backed by a 
texture map that loads and displays custom images for each tile state. The implementation uses SFML’s rendering pipeline, 
coordinate‐to‐index conversion, and a full row/column/diagonal evaluation system to detect winners efficiently and keep the gameplay responsive.

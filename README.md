
# Battleship Game

The Battleship Game is a two-player game that simulates a naval battle. However, in this implementation, it's a single-player game where the player competes against the computer. The player places their ships on a 9x9 grid and tries to sink the computer's ships before the computer sinks theirs.

This implementation of the game uses a simple randomizer to determine the computer's moves. The computer randomly selects a cell on the player's grid and checks if there is a ship at that location. If there is, the computer marks that cell as a hit and continues to fire at adjacent cells until the ship is sunk. If there isn't, the computer marks that cell as a miss and the player takes their turn.

This program is written in C++ and uses basic console input/output to interact with the player. It can be compiled and run on any standard C++ compiler.
# Flappy-Bird-EasyX
Flappy Bird Game in C++ ; This project is a C++ implementation of the popular Flappy Bird game.

This is a C++ implementation of the Flappy Bird game using the EasyX graphics library. The game involves controlling a bird by clicking the screen to avoid obstacles (columns). The project uses object-oriented programming to structure different functionalities of the game.
![gamePhoto1](picture/start.png =600*600)  ![gamePhoto2](picture/gaming.png =600*600)  ![gamePhoto3](picture/over.png =600*600)
## Project Structure

- `CBirdAPP`: Main game class, manages game state and core logic.
  - `CBackGround m_BackGround`: Background object
  - `CGround m_Ground`: Ground object
  - `CPlayerBird m_PlayerBird`: Player bird object
  - `CColumnBox m_columnBox`: Manages columns
  - `CBeforeGame m_BeforeGame`: Pre-game interface
  - `CAfterGame m_AfterGame`: Post-game interface

- `CBackGround`: Handles game background.
  - `IMAGE m_imgBack`: Background image
  - `void InitBackGround()`: Initialize background
  - `void ShowBackGround()`: Display background

- `CGround`: Handles game ground.
  - `IMAGE m_imgGround`: Ground image
  - `void InitGround()`: Initialize ground
  - `void ShowGround()`: Display ground
  - `void MoveGround(int step)`: Move ground
  - `bool ITouchGround(CPlayerBird* player)`: Check if the player bird touches the ground

- `CPlayerBird`: Handles the player-controlled bird.
  - `IMAGE m_imgPlayer[8]`: Bird animation frames
  - `void InitPlayerBird()`: Initialize bird
  - `void ShowPlayerBird()`: Display bird
  - `void MovePlayerBird()`: Move bird

- `CColumn`: Handles obstacle columns.
  - `IMAGE m_imgColumn`: Column image
  - `void InitColumn()`: Initialize column
  - `void ShowColumn()`: Display column
  - `void MoveColumn(int step)`: Move column
  - `bool ITouchBird(CPlayerBird* player)`: Check if the column touches the player bird

- `CColumnBox`: Manages multiple column objects.
  - `list<CColumn*> m_ColLst`: List of column objects
  - `void InitColumnBox()`: Initialize columns
  - `void ShowAllColumn()`: Display all columns
  - `void MoveAllColumn(int step)`: Move all columns

- `CBeforeGame`: Handles pre-game interface.
  - `void InitBeforeGame()`: Initialize pre-game interface
  - `void ShowBeforeGame()`: Display pre-game interface
  - `void StartGame()`: Start the game

- `CAfterGame`: Handles post-game interface.
  - `void InitAfterGame()`: Initialize post-game interface
  - `void ShowAfterGame()`: Display post-game interface
  - `void ReStartGame()`: Restart the game

## Features

- Control a bird to fly through obstacles
- Simple yet addictive gameplay
- Score tracking
- Basic collision detection
- Game restart functionality

## Requirements

- C++ compiler (e.g., g++)
- EasyX graphics library (for Windows)

## Acknowledgements

- Inspired by Dong Nguyen's original Flappy Bird game
- EasyX graphics library



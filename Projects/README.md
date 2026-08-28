# Projects

This folder contains small desktop games: Java Swing titles in this directory, and original Pygame games in [`games/`](games/).

## Pygame Games

See [`games/README.md`](games/README.md). Install Pygame, then run any script:

```powershell
cd games
python -m pip install -r requirements.txt
python pong.py
```

# Java Swing Projects

This folder also contains small desktop games built with Java Swing.

## Requirements

- Java Development Kit (JDK) 17 or newer
- `javac` and `java` available from the terminal

Check your Java installation:

```powershell
java -version
javac -version
```

If `java` works but `javac` does not, install a JDK instead of only a JRE, then add the JDK `bin` folder to your PATH.

## How To Build

Open PowerShell from the repository root and move into this folder:

```powershell
cd "d:\Dev\GitHub\Code Practice\Code-Problems\Projects"
```

Compile all Java projects:

```powershell
javac App.java Minesweeper.java SnakeApp.java SnakeGame.java
```

This creates `.class` files in the same folder.

## How To Run

Run Minesweeper:

```powershell
java App
```

Run Snake:

```powershell
java SnakeApp
```

## How To Test The Build

1. Run the compile command:

```powershell
javac App.java Minesweeper.java SnakeApp.java SnakeGame.java
```

2. If compilation finishes without errors, run each app:

```powershell
java App
java SnakeApp
```

3. Test Minesweeper:

- Choose a difficulty from the popup.
- Left-click tiles to reveal them.
- Right-click tiles to flag or unflag mines.
- Confirm the timer starts after the first click.
- Confirm the win/loss popup appears when the game ends.
- Use "Play Again" and "Change Difficulty" from the popup.

4. Test Snake:

- Use the arrow keys to move.
- Confirm the snake wraps through screen edges and appears on the opposite side.
- Eat normal food and confirm the score increases by 10 and the snake grows by 1.
- Confirm normal food never appears on the snake body.
- After 5 normal foods, confirm the big 2x2 bonus ball appears.
- Eat the big ball within 5 seconds and confirm the score increases by 100.
- Let the big ball expire and confirm it disappears.
- Turn into the snake body and confirm the game ends.
- Press `Space` to pause/resume and `R` to restart.

## Project Explanations

### Minesweeper

Files:

- `App.java`
- `Minesweeper.java`

`App.java` starts the Swing app on the Event Dispatch Thread. `Minesweeper.java` contains the game UI and logic.

Main features:

- Difficulty selection popup: Beginner, Intermediate, Expert
- First-click-safe mine placement
- Timer and remaining mine counter
- Right-click flagging
- Flood reveal for empty areas
- Win/loss result popup with replay options
- Visual board styling with colored numbers, flags, mines, and status text

### Snake

Files:

- `SnakeApp.java`
- `SnakeGame.java`

`SnakeApp.java` starts the Swing app on the Event Dispatch Thread. `SnakeGame.java` contains the full game window, board rendering, keyboard controls, scoring, food placement, and game loop.

Main features:

- Level 1 classic Snake gameplay
- Arrow-key movement
- Wall wrapping from one side to the opposite side
- Self-collision game over
- Normal food worth 10 points
- Snake grows by 1 unit for each normal food
- Normal food placement avoids all snake body cells
- Big 2x2 bonus ball after every 5 normal foods
- Bonus ball lasts 5 seconds and is worth 100 points
- Pause with `Space`, restart with `R`, or use the Restart button
- Custom painted UI with grid, score bar, snake body, food, and overlays

## Clean Build Files

To remove compiled `.class` files:

```powershell
Remove-Item *.class
```

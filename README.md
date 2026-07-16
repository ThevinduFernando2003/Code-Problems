# Code-Problems

A personal collection of coding practice solutions, competitive programming problems, and small projects across multiple platforms and languages.

## Repository Structure

| Folder | Description |
|--------|-------------|
| [`Projects/`](Projects/) | Java Swing desktop games (Minesweeper, Snake) |
| [`CSES_Problems/`](CSES_Problems/) | C++ solutions for [CSES Problem Set](https://cses.fi/problemset/) |
| [`Leetcode/`](Leetcode/) | LeetCode problem solutions |
| [`EulerProblems/`](EulerProblems/) | Project Euler solutions (Python & C++) |
| [`HackerRank/`](HackerRank/) | HackerRank solutions (Algorithms, DS, Mathematics) |
| [`CodeRally/`](CodeRally/) | CodeRally weekly test and contest solutions |
| [`SEPrepKit/`](SEPrepKit/) | Software engineering interview prep problems |
| [`WeeklyQuiz/`](WeeklyQuiz/) | Weekly quiz and challenge solutions |
| [`DSA/`](DSA/) | Data structures and algorithms practice |

## Quick Start

### Java Projects (Minesweeper & Snake)

See [`Projects/README.md`](Projects/README.md) for full build and test instructions.

```powershell
cd Projects
javac App.java Minesweeper.java SnakeApp.java SnakeGame.java
java App        # Minesweeper
java SnakeApp   # Snake
```

### C++ Solutions

Compile and run individual files with g++:

```powershell
cd CSES_Problems
g++ -std=c++17 1weirdAlgorithm.cpp -o solution.exe
.\solution.exe
```

### Python Solutions

Run scripts directly:

```powershell
cd SEPrepKit
python smallestmissingpositive.py
```

## Featured Projects

### Minesweeper (`Projects/`)

Classic minesweeper with difficulty levels, timer, mine counter, first-click safety, and win/loss popups.

### Snake (`Projects/`)

Arcade-style snake game with wall wrapping, scoring, timed bonus food, pause/restart controls, and custom UI.

## Recent Additions

- **Projects/Snake** — Swing snake game with bonus balls and score tracking
- **Projects/Minesweeper** — Full minesweeper with timer, difficulty, and popups
- **CodeRally/WeeklyTest 1** — Array optimization and BFS graph problems
- **SEPrepKit/smallestmissingpositive.py** — O(n) in-place smallest missing positive integer

## Languages

- **C++** — CSES, CodeRally, HackerRank, Euler
- **Python** — LeetCode, Euler, SEPrepKit, WeeklyQuiz
- **Java** — Desktop game projects

## Requirements

- **Java:** JDK 17+ (`javac`, `java`)
- **C++:** g++ with C++17 support
- **Python:** Python 3.x

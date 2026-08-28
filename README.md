# Code-Problems

A personal collection of coding practice solutions, competitive programming problems, and small projects across multiple platforms and languages.

## Repository Structure

| Folder | Description |
|--------|-------------|
| [`Projects/`](Projects/) | Java Swing games plus original [Pygame games](Projects/games/) |
| [`CSES_Problems/`](CSES_Problems/) | C++ solutions for [CSES Problem Set](https://cses.fi/problemset/) (86 solved) |
| [`Leetcode/`](Leetcode/) | LeetCode problem solutions |
| [`EulerProblems/`](EulerProblems/) | [Project Euler](https://projecteuler.info/) solutions 1–100 (Python) |
| [`HackerRank/`](HackerRank/) | HackerRank solutions (Algorithms, DS, Mathematics) |
| [`CodeRally/`](CodeRally/) | CodeRally weekly test and contest solutions |
| [`SEPrepKit/`](SEPrepKit/) | Software engineering interview prep problems |
| [`SQL/`](SQL/) | [Code360 Top 100 SQL](https://www.naukri.com/code360/problem-lists/top-100-sql-problems) (q01–q100) |
| [`WeeklyQuiz/`](WeeklyQuiz/) | Weekly quiz and challenge solutions |
| [`DSA/`](DSA/) | Data structures and algorithms practice |

## Quick Start

### Pygame Games

See [`Projects/games/README.md`](Projects/games/README.md). Install with `pip install -r Projects/games/requirements.txt`, then run any script such as `python pong.py`.

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

### Pygame collection (`Projects/games/`)

Original Pygame versions of classic arcade, board, card, and action games (Pong, Snake, Tetris, Pac-Man, Chess, and more). Each game is a single Python file.

## Project Euler Progress

Solutions 1–100 live in [`EulerProblems/`](EulerProblems/) using `{number}{problemName}.py` naming. See [`EulerProblems/README.md`](EulerProblems/README.md) for the full index.

Reference: [Project Euler](https://projecteuler.info/) · [Problems 51–100](https://projecteuler.info/problems;page=2)

## SQL Progress

100 solutions in [`SQL/`](SQL/) as `q{number}{ProblemName}.sql`. See [`SQL/README.md`](SQL/README.md).

Reference: [Code360 Top 100 SQL](https://www.naukri.com/code360/problem-lists/top-100-sql-problems)

## CSES Progress

Solutions follow the `{number}{problemName}.cpp` naming convention in [`CSES_Problems/`](CSES_Problems/).

| Section | Problems | Status |
|---------|----------|--------|
| Introductory Problems | 1–19 | Complete |
| Sorting and Searching | 20–54 | Complete |
| Dynamic Programming | 55–76 | Complete |
| Graph Algorithms | 77–86 | In progress |

Reference: [CSES Problem Set](https://cses.fi/problemset/) · [GeeksforGeeks CSES guide](https://www.geeksforgeeks.org/dsa/cses-problem-set-solutions/)

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

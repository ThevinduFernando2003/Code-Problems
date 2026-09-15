# CSES Problem Set

C++ solutions for the [CSES Problem Set](https://cses.fi/problemset/). Each file has the problem name, **pseudocode**, then a complete program.

Naming: `{number}{camelCaseTitle}.cpp`

The live CSES site has **400+** tasks. This folder is a growing numbered set (currently **1–192**), not a claim that every CSES task exists here. Remaining sections (harder range queries, string/geometry extras, advanced graphs, counting, additional I/II, interactive) can be added the same way.

## Status

| # | Section | Coverage in this folder |
|---|---------|-------------------------|
| 1–19 | Introductory Problems | Complete (classic list) |
| 20–54 | Sorting and Searching | Complete |
| 55–76 | Dynamic Programming | Complete |
| 77–112 | Graph Algorithms | Complete through Distinct Routes |
| 113–136 | Range Queries | Sums, minima, xor, updates, forest, hotel/list/salary, prefix/pizzeria, subarray/distinct, 2D forest, lazy, polynomial, persistent copies |
| 120–125, 137–144 | Tree Algorithms | Subordinates through centroid (plus distances II, LCA, path/subtree queries, HLD, distinct colors) |
| 145–156, 190–192 | Mathematics | Exponentiation, divisors, binomials, derangements, Fibonacci, Catalan, Josephus queries, primes, dice, multiplication table |
| 157–163 | String Algorithms | Word combinations, KMP/Z, borders, periods, rotation, Manacher |
| 164–170 | Geometry | Orientation, segments, area, point-in-polygon, lattice, closest pair, hull |
| 171–172 | Advanced Techniques | Meet in the middle, Hamming distance |
| 173–181 | Sliding window / bitwise | Window sum/min/xor/median/cost/distinct/mex, counting bits, max xor subarray |
| 182–189 | Games / extra intro | Nim I–II, stick game, mex grid, knight grid, grid coloring I, Raab I, another game |

## Notes

- Use 64-bit integers where CSES constraints need them (`Weird Algorithm`, prefix sums, distances).
- `Counting Rooms` treats `.` as floor and `#` as wall.
- `Shortest Routes I` is a **directed** Dijkstra.
- `High Score` uses Bellman-Ford and only treats a positive cycle as unbounded if it can still reach `n`.
- Skip `*-DESKTOP-RTUARGV.cpp` junk copies.

Reference: [CSES Problem Set](https://cses.fi/problemset/)

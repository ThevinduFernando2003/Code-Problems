#include <bits/stdc++.h>
using namespace std;

/*
Coderbyte — Sudoku Quadrant Checker

strArr has 9 strings of 9 characters (digits or 'x'). A cell is illegal
if its digit repeats in its row, column, or 3x3 box. Return the sorted
unique 1-9 box numbers that contain an illegal cell, or "legal".

Boxes:
  1 2 3
  4 5 6
  7 8 9

Examples:
  a valid board -> "legal"
  duplicates in boxes 3 and 5 -> "3,5"

Pseudocode
----------
function box(r, c): return (r/3)*3 + (c/3) + 1
function SudokuQuadrantChecker(board):
    mark every cell whose digit appears more than once in its row, col, or box
    collect box numbers of marked cells
    if none: return "legal"
    return them sorted and comma-separated
*/

int boxId(int r, int c) { return (r / 3) * 3 + (c / 3) + 1; }

string SudokuQuadrantChecker(vector<string> b) {
    bool bad[9][9] = {};
    auto mark = [&](vector<pair<int, int>> cells) {
        int cnt[10] = {};
        for (auto [r, c] : cells) if (isdigit((unsigned char)b[r][c])) ++cnt[b[r][c] - '0'];
        for (auto [r, c] : cells) {
            if (isdigit((unsigned char)b[r][c]) && cnt[b[r][c] - '0'] > 1) bad[r][c] = true;
        }
    };
    for (int r = 0; r < 9; ++r) {
        vector<pair<int, int>> cells;
        for (int c = 0; c < 9; ++c) cells.push_back({r, c});
        mark(cells);
    }
    for (int c = 0; c < 9; ++c) {
        vector<pair<int, int>> cells;
        for (int r = 0; r < 9; ++r) cells.push_back({r, c});
        mark(cells);
    }
    for (int br = 0; br < 9; br += 3) {
        for (int bc = 0; bc < 9; bc += 3) {
            vector<pair<int, int>> cells;
            for (int r = br; r < br + 3; ++r)
                for (int c = bc; c < bc + 3; ++c) cells.push_back({r, c});
            mark(cells);
        }
    }
    set<int> boxes;
    for (int r = 0; r < 9; ++r)
        for (int c = 0; c < 9; ++c)
            if (bad[r][c]) boxes.insert(boxId(r, c));
    if (boxes.empty()) return "legal";
    string out;
    for (int id : boxes) {
        if (!out.empty()) out += ',';
        out += to_string(id);
    }
    return out;
}

int main() {
    vector<string> board(9);
    for (int i = 0; i < 9; ++i) cin >> board[i];
    cout << SudokuQuadrantChecker(board) << endl;
    return 0;
}

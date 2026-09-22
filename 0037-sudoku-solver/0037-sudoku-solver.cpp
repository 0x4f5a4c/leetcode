// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// we have to modify the board 
class Solution {
public:
    bool isValid(vector<vector<char>> &grid, int row, int col, char digit) {
        // row and column validate
        for (int i = 0; i < 9; ++i) {
            if (grid[row][i] == digit || grid[i][col] == digit) return false;
        }

        int start_i = row/3 * 3;
        int start_j = col/3 * 3;
        // now validate the grid
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                if (grid[start_i + k][start_j + l] == digit) return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>> &grid) {
        // traversing in the grid
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                // now check is it a .
                if (grid[i][j] == '.') { // yes now perform the operatin
                    // we have options from 1 to 9
                    for (char d = '1'; d <= '9'; d++) {
                        // now before adding the grid check the digit is valid or not then move ahead
                        if (isValid(grid, i, j, d)) {
                            grid[i][j] = d; // convert the digit into the char and update
                            // then explore now
                            if (solve(grid)) return true;
                            // otherwise backtrack
                            grid[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

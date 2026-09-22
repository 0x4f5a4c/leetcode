// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// another solution 
// better approach

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                // now check the element in the row, col and grid
                string row = string(1, board[i][j]) + "_ROW_" + to_string(i);
                string col = string(1, board[i][j]) + "_COL_" + to_string(j);
                string grid = string(1, board[i][j]) + "_GRID_" + to_string(i/3) + to_string(j/3);

                if (st.find(row) != st.end() || st.find(col) != st.end() || st.find(grid) != st.end()) return false;
                st.insert(row);
                st.insert(col);
                st.insert(grid);
            }
        }

        return true;
    }
};


// brute force soluiton
class Solution {
public:

    bool Traversal(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
        unordered_set<char> st;
        for (int i = sr; i <= er; ++i) {
            for (int j = sc; j <= ec; ++j) {
                if (board[i][j] == '.') continue;
                if (st.find(board[i][j]) != st.end()) return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // verifying the row
        for (int row = 0; row < 9; ++row) {
            unordered_set<char> st;
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') continue;
                if (st.find(board[row][col]) != st.end()) return false;  // means the same row contains duplicate element
                st.insert(board[row][col]);  // means insert the value into the set
            }
        }

        // now verifying the column
        for (int col = 0; col < 9; ++col) {
            unordered_set<char> st;
            for (int row = 0; row < 9; ++row) {
                if (board[row][col] == '.') continue;
                if (st.find(board[row][col]) != st.end()) return false; // means same column contains duplicate elements
                st.insert(board[row][col]);
            }
        }

        // now verifying the 3x3 grid
        for (int starting_row = 0; starting_row < 9; starting_row += 3) {  // starting_row += 3 helps to jump into the next 3x3 grid's starting row
            int ending_row = starting_row + 2; // calculating the ending row of 3x3 sub-grid
            for (int starting_col = 0; starting_col < 9; starting_col += 3) { // starting_col += 3 helps to jump into the next 3x3 grid's starting col
                int ending_col = starting_col + 2;  // calulating the ending column of 3x3 sub-grid
                // now we have **sr, er, sc, ec**
                // now traverse in the grid
                if (!Traversal(board, starting_row, ending_row, starting_col, ending_col)) return false;
            }
        }

        return true;
    }
};

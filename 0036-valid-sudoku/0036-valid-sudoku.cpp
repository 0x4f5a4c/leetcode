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
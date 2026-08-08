class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int &peri) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            peri++;
            return;
        }

        if (grid[i][j] == -1) return;
        grid[i][j] = -1;

        dfs(grid, i + 1, j, m, n, peri);
        dfs(grid, i - 1, j, m, n, peri);
        dfs(grid, i, j + 1, m, n, peri);
        dfs(grid, i, j - 1, m, n, peri);
    }

    // using bfs
    
    int bfs(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>> &directions) {
        int peri = 0;
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = -1;  // mark as visited;

        while (!que.empty()) {
            auto [row, col] = que.front();
            que.pop();

            for (auto &dir : directions) {
                int new_i = row + dir[0];
                int new_j = col + dir[1];

                if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || grid[new_i][new_j] == 0) {
                    peri++;
                } else if (grid[new_i][new_j] == -1) continue;
                else {
                    que.push({new_i, new_j});
                    grid[new_i][new_j] = -1;  // mark as visited
                }
                    
            }
        }

        return peri;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int peri = 0;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // using bfs
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    return bfs(grid, i, j, m, n, directions);
                }
            }
        }    

        return -1;
    }
};
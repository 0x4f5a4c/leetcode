class Solution {
public:
    int m, n;
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
            return;
        grid[i][j] = '$'; // mark as visited

        // now dfs calls
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = '$'; // mark as visited;

        while (!que.empty()) {
            auto it = que.front();
            que.pop();

            for (auto &dir : directions) {
                int new_i = it.first + dir[0];  
                int new_j = it.second + dir[1];

                if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n ||
                    grid[new_i][new_j] != '1')
                    continue;
                else {
                    que.push({new_i, new_j});
                    grid[new_i][new_j] = '$';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int islands = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }
};
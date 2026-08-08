class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        long long m = grid.size();
        long long n = grid[0].size();

        long long ans = 0;

        for(long long i = 0; i < m; i++){
            for(long long j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    long long cnt = 4;
                    if(j+1 < n && grid[i][j+1] == 1){
                        cnt = cnt - 1;
                    }

                    if(i+1 < m && grid[i+1][j] == 1){
                        cnt = cnt - 1;
                    }

                    if(j-1 >= 0 && grid[i][j-1] == 1){
                        cnt = cnt - 1;
                    }

                    if(i-1 >= 0 && grid[i-1][j] == 1){
                        cnt = cnt - 1;
                    }

                    ans = ans + cnt;
                }
            }
        }

        return ans;
    }
};
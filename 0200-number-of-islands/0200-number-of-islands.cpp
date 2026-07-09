class Solution {
private:
    void backtrack(vector<vector<char>>& grid, int i, int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';

        backtrack(grid, i+1, j, n, m);
        backtrack(grid, i-1, j, n, m);
        backtrack(grid, i, j+1, n, m);
        backtrack(grid, i, j-1, n, m);
        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    backtrack(grid, i, j, n, m);
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        k = k%(n*m);
        if(k == 0) return grid;

        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int old_1d = i * m + j;
                int new_1d = (old_1d + k) % (n*m);
                
                int new_r = new_1d / m;
                int new_c = new_1d % m;
                
                ans[new_r][new_c] = grid[i][j];
            }
        }

        return ans;
    }
};
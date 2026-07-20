class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        k = k%(n*m);
        if(k == 0) return grid;

        vector<vector<int>> ans(n, vector<int>(m, 0));
        while(k--){
            int temp = grid[n-1][m-1];
            int prev = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m-1; j++){
                    ans[i][j+1] = grid[i][j];
                }
                ans[i][0] = prev;
                prev = grid[i][m-1];
            }

            ans[0][0] = temp;

            grid = ans;
        }

        return ans;
    }
};
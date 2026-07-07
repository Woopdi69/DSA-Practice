class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0, fresh = 0;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;

        while(!q.empty()){
            int s = q.size();
            bool found = false;
            for(int i = 0; i < s; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(auto d : dir){
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        found = true;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            if(found) ans++;
        }

        return fresh == 0 ? ans : -1;
    }
};
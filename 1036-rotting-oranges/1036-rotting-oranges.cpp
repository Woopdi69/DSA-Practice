class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), time = 0, normal = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    normal++;
                }else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        if(normal <= 0) return 0;

        while(!q.empty()){
            int size = q.size();
            bool found = false;

            for(int k = 0; k < size; k++){
                auto [i, j] = q.front();
                q.pop();

                for(auto d : dir){
                    int ni = i+d[0];
                    int nj = j+d[1];

                    if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == 1){
                        normal--;
                        grid[ni][nj] = 2;
                        q.push({ni, nj});
                        found = true;
                    }
                }
            }
            
            if(found) time++;
        }

        if(normal > 0){
            return -1;
        }
        return time;
    }
};
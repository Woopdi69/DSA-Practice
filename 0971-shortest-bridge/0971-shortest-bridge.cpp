class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m, queue<pair<int,int>>& q){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1){
            return;
        }

        grid[i][j] = 2;
        q.push({i, j});
        dfs(grid, i+1, j, n, m, q);
        dfs(grid, i-1, j, n, m, q);
        dfs(grid, i, j+1, n, m, q);
        dfs(grid, i, j-1, n, m, q);
    }

    int bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid){
        int cur = 0;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            int size = q.size();
            for(int k = 0; k < size; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(auto d : dir){
                    int ni = i + d[0];
                    int nj = j + d[1];

                    if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size()){
                        if(grid[ni][nj] == 1) return cur;
                        if(grid[ni][nj] == 0){
                            grid[ni][nj] = 2;
                            q.push({ni, nj});
                        }
                    }
                }
            }
            cur++;
        }

        return cur;
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        int found = false;

        for(int i = 0; i < n && !found; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, n, m, q);
                    found = true;
                    break;
                }
            }
        }
        
        return bfs(q, grid);
    }
};
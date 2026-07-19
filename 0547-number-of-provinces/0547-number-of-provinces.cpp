class Solution {
private:
    vector<vector<int>> adj;
    void add(int u, int v){
        adj[u].push_back(v);
    }

    void dfs(int i, vector<bool>& visited){
        visited[i] = true;

        for(auto n : adj[i]){
            if(!visited[n]){
                dfs(n, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        adj.resize(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 0 || i == j){
                    continue;
                }

                add(i, j);
            }
        }

        vector<bool> visited(n, false);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, visited);
                ans++;
            }
        }

        return ans;
    }
};
class Solution {
private:
    vector<vector<int>> adj;
    void add(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int i, vector<int>& visited, int& node, int& count){
        visited[i] = 1;
        node++;
        count += adj[i].size();

        for(auto n : adj[i]){
            if(visited[n] == 0){
                dfs(n, visited, node, count);
            }   
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vector<int> visited(n, 0);
        int ans = 0;

        for(auto v : edges){
            add(v[0], v[1]);
        }

        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                int node = 0;
                int count = 0;

                dfs(i, visited, node, count);
                if(count == node*(node-1)){
                    ans++;
                }
            }
        }

        return ans;
    }
};
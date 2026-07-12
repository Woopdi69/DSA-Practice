class Solution {
private:
    vector<vector<int>> adj;
    vector<vector<int>> ans;
    void add(int u, int v){
        adj[u].push_back(v);
    }

    void dfs(int i, vector<int>& cur, int size){
        cur.push_back(i);
        if(i == size){
            ans.push_back(cur);
            cur.pop_back();
            return;
        }

        for(auto n : adj[i]){
            dfs(n, cur, size);
        }
        cur.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        adj.resize(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < graph[i].size(); j++){
                add(i, graph[i][j]);
            }
        }

        vector<int> cur;
        dfs(0, cur, n-1);
        return ans;
    }
};
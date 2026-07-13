class Solution {
private:
    vector<vector<int>> adj;
    void add(int u, int v){
        adj[v].push_back(u);
    }

    bool dfs(int i, vector<int>& visited, stack<int>& stk){
        if(visited[i] == 1) return true;
        if(visited[i] == 2) return false;

        visited[i] = 1;
        for(auto n : adj[i]){
            if(dfs(n, visited, stk)){
                return true;
            }
        }

        stk.push(i);
        visited[i] = 2;
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        for(auto e : prerequisites){
            add(e[0], e[1]);
        }

        vector<int> visited(numCourses, 0);
        stack<int> stk;
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(dfs(i, visited, stk)){
                    return {};
                }
            }
        }

        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }

        return ans;
    }
};
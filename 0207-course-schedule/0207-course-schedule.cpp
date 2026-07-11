class Solution {
private:
    vector<vector<int>> adj;
    void add(int u, int v){
        adj[v].push_back(u);
    }

    bool hasCycle(int i, vector<int>& visited){
        if(visited[i] == 1) return true;
        if(visited[i] == 2) return false;
        
        visited[i] = 1;
        for(auto n : adj[i]){
            if(hasCycle(n, visited)){
                return true;
            }
        }

        visited[i] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        for(auto v : prerequisites){
            add(v[0], v[1]);
        }

        vector<int> visited(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(hasCycle(i, visited)){
                    return false;
                }
            }
        }

        return true;
    }
};
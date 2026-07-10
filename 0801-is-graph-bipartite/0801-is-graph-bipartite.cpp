class Solution {
private:
    bool BFS(int cur, vector<int>& color, vector<vector<int>>& graph){
        queue<int> q;
        q.push(cur);
        color[cur] = 0;

        while(!q.empty()){
            int top = q.front();
            q.pop();
                    
            for(auto nei : graph[top]){
                if(color[nei] == -1){
                    if(color[top] == 0){
                        color[nei] = 1;
                    }else{
                        color[nei] = 0;
                    }

                    q.push(nei);
                }else{
                    if(color[nei] == color[top]) return false;
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1 && !BFS(i, color, graph)){
                return false;
            }
        }

        return true;
    }
};
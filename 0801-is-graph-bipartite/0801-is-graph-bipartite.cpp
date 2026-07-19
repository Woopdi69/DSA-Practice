class Solution {
private:
    bool bfs(int i, vector<int>& color, vector<vector<int>>& graph){
        queue<int> q;
        q.push(i);
        color[i] = 0;

        while(!q.empty()){
            int t = q.front();
            q.pop();

            for(auto n : graph[t]){
                if(color[n] == -1){
                    if(color[t] == 0){
                        color[n] = 1;
                    }else{
                        color[n] = 0;
                    }
                    q.push(n);
                }else if(color[n] == color[t]){
                    return false;
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
            if(color[i] == -1 && !bfs(i, color, graph)){
                return false;
            }
        }

        return true;
    }
};
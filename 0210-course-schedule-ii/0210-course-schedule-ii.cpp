class Solution {
private:
    vector<vector<int>> adj;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        vector<int> in(numCourses, 0);
        for(auto e : prerequisites){
            adj[e[1]].push_back(e[0]);
            in[e[0]]++;
        }

        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int i = q.front();
            q.pop();

            for(auto n : adj[i]){
                in[n]--;
                if(in[n] == 0){
                    q.push(n);
                }
            }
            ans.push_back(i);
        }

        if(ans.size() == numCourses){
            return ans;
        }

        return {};
    }
};
class Solution {
private:
    void DFS(vector<vector<int>>& isConnected, vector<int>& visited, int val){
        visited[val] = 1;

        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[val][i] == 1 && visited[i] == 0){
                DFS(isConnected, visited, i);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<int> visited(n, 0);
        
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                ans++;
                DFS(isConnected, visited, i);

            }
        }
        
        return ans;
    }
};
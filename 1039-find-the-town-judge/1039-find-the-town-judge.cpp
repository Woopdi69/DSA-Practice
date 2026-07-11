class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> visited(n+1, 0);

        for(auto v : trust){
            int i = v[0];
            int j = v[1];

            visited[i]--;
            visited[j]++;
        }

        for(int i = 1; i <= n; i++){
            if(visited[i] == n-1){
                return i;
            }
        }

        return -1;
    }
};
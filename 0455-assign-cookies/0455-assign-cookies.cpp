class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        if(s.empty()) return 0;
        sort(g.begin(), g.end());
        priority_queue<int> pq;
        for(int i : s){
            pq.push(i);
        }

        for(int i = g.size()-1; i >= 0; i--){
            if(pq.empty()) break;

            if(g[i] > pq.top()){
                continue;
            }else{
                ans++;
                pq.pop();
            }
        }

        return ans;
    }
};
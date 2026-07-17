class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0, mini = INT_MAX;
        for(int i : prices){
            mini = min(i, mini);
            prof = max(prof, i-mini);
        }

        return prof;
    }
};
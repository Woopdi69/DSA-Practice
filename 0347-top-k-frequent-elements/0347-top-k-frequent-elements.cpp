class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int i : nums){
            freq[i]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto pair : freq){
            pq.push({pair.second, pair.first});
        }

        vector<int> ans;
        while(!pq.empty() && k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};
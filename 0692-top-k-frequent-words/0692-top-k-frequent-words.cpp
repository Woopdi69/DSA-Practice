class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> map;
        for(string s : words){
            map[s]++;
        }

        auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first; 
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq;
        for(auto pair : map){
            pq.push({pair.second, pair.first});
        }

        while(!pq.empty() && k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};
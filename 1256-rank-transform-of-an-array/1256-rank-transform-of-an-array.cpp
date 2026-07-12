class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_nums(arr.begin(), arr.end());
        sort(sorted_nums.begin(), sorted_nums.end());
        
        unordered_map<int, int> ranks;
        int current_rank = 1;
        
        for (int num : sorted_nums) {
            if (ranks.find(num) == ranks.end()) {
                ranks[num] = current_rank;
                current_rank++;
            }
        }
        
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = ranks[arr[i]];
        }
        
        return arr;
    }
};

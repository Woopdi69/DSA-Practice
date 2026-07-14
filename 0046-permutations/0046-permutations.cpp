class Solution {
private:
    vector<vector<int>> ans;
    void backtrack(int i, vector<int>& nums){
        if(i >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            backtrack(i+1, nums);
            swap(nums[i], nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, nums);

        return ans;
    }
};
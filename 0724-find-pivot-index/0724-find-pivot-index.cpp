class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, left = 0;
        for(int i : nums){
            sum += i;
        }

        for(int i = 0; i < nums.size(); i++){
            if(sum - left - nums[i] == left){
                return i;
            }

            left += nums[i];
        }

        return -1;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        while(right < n){
            while(right < n && nums[right] == 0){
                right++;
            }

            if(right < n){
                swap(nums[right], nums[left]);
                left++;
                right++;
            }
        }
    }
};
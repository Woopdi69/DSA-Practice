class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0, count = 0;
        int left = 0, right = 0;

        while(right < nums.size()){
            if(nums[right] == 0){
                count++;
            }

            while(left < nums.size() && count > k){
                if(nums[left] == 0){
                    count--;
                }
                left++;
            }

            ans = max(ans, right-left+1);
            right++;
        }

        return ans;
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, cur = 0;
        int left = 0, right = 0;

        while(right < nums.size()){
            cur += nums[right];

            while(cur >= target){
                ans = min(ans, right-left+1);
                cur -= nums[left];
                left++;
            }

            right++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
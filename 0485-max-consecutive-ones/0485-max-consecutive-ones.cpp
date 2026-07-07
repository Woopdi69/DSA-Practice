class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right = 0;
        int ans = 0, n = nums.size();

        while(right < n){
            
            if(nums[right] == 0){
                ans = max(ans, right-left);
                left = right+1;
            }

            right++;
        }

        ans = max(ans, right-left);

        return ans;
    }
};
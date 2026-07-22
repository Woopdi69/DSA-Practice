class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cur = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                ans = max(cur, ans);
                cur = 0;
            }else{
                cur++;
            }
        }

        ans = max(cur, ans);
        return ans;
    }
};
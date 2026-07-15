class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1, -1};
        }
        int left = 0, right = nums.size()-1;
        vector<int> ans(2, -1);
        while(left <= right){
            int mid = left+(right-left)/2;

            if(nums[mid] == target){
                int l = mid, r = mid;
                while(l-1 >= 0 && nums[l-1] == nums[mid]){
                    l--;
                }
                while(r+1 < nums.size() && nums[r+1] == nums[mid]){
                    r++;
                }
                ans[0] = l;
                ans[1] = r;
                return ans;
            }else if(nums[mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        return ans;
    }
};
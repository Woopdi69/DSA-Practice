class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1, -1};
        }
        int left = 0, right = nums.size()-1;
        int l = -1, r = -1;
        vector<int> ans(2, -1);

        while(left <= right){
            int mid = left+(right-left)/2;

            if(nums[mid] == target){
                l = mid;
                right = mid-1;
            }else if(nums[mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        left = 0;
        right = nums.size()-1;
        while(left <= right){
            int mid = left+(right-left)/2;

            if(nums[mid] == target){
                r = mid;
                left = mid+1;
            }else if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        ans[0] = l;
        ans[1] = r;
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& nums) {
        int ans = 0, n = nums.size();
        vector<int> left(n, 0), right(n, 0), arr(n, INT_MAX);
        left[0] = max(left[0], nums[0]);
        right[n-1] = max(right[n-1], nums[n-1]);

        for(int i = 1; i < n; i++){
            left[i] = max(nums[i], left[i-1]);
        }

        for(int i = n-2; i >= 0; i--){
            right[i] = max(nums[i], right[i+1]);
        }

        for(int i = 0; i < n; i++){
            arr[i] = min(left[i], right[i]);
        }

        for(int i = 0; i < n; i++){
            ans += abs(arr[i]-nums[i]);
        }

        return ans;
    }
};
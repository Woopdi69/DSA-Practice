class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++){
            int idx = distance(nums2.begin(), find(nums2.begin(), nums2.end(), nums1[i]));

            for(idx; idx < nums2.size(); idx++){
                if(nums2[idx] > nums1[i]){
                    ans[i] = nums2[idx];
                    break;
                }
            }
        }

        return ans;
    }
};
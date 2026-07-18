/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* construct(vector<int>& nums, int left, int right){
        if(left > right) return nullptr;

        int mid = left + (right-left)/2;
        TreeNode* n = new TreeNode(nums[mid]);

        n->left = construct(nums, left, mid-1);
        n->right = construct(nums, mid+1, right);

        return n;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 1){
            TreeNode* head = new TreeNode(nums[0]);
            return head;
        }

        return construct(nums, 0, nums.size()-1);
    }
};
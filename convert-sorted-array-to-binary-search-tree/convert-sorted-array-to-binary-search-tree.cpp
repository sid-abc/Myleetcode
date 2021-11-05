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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct(nums, 0, nums.size()-1);
    }
    
    TreeNode* construct(vector<int> nums, int l, int r) {
        if(l > r)
            return NULL;
        int mid = (l+r)/2;
        TreeNode *t = new TreeNode;
        t->val = nums[mid];
        t->left = construct(nums, l, mid-1);
        t->right = construct(nums, mid+1, r);
        return t;
    }
};
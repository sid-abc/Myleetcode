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
    
    int max_index(vector<int> nums, int l, int r) {
        int max_i = l;
        for(int i=l;i<r;i++)
            if(nums[max_i] < nums[i])
                max_i = i;
        
        return max_i;
    }
    
    TreeNode* construct(vector<int> nums, int l, int r) {
        if(l==r)
            return NULL;
        int max_i = max_index(nums, l, r);
        TreeNode *p = new TreeNode;
        p->val = nums[max_i];
        p->left = construct(nums, l, max_i);
        p->right = construct(nums, max_i+1, r);
        
        return p;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }
};
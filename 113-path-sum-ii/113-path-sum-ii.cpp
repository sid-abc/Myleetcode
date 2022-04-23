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
    vector<vector<int>> ans;
    vector<int> temp;
    
    void solve(TreeNode *p, int targetSum) {
        if(!p)
            return;
        temp.push_back(p->val);
        if(targetSum == p->val && !p->left && !p->right)
            ans.push_back(temp);
        solve(p->left, targetSum - p->val);
        solve(p->right, targetSum - p->val);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum);
        return ans;
    }
};
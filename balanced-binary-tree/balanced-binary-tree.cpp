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
    int height(TreeNode *p) {
        if(p==NULL)
            return 0;
        int x = height(p->left);
        int y = height(p->right);
        
        if(x==-1 || y==-1)
            return -1;
        else if(abs(x-y) > 1)
            return -1;
        else 
            return max(x, y) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        
        return height(root) != -1;
    }
};
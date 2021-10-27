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
    bool isValidBST(TreeNode* root) {
        TreeNode * prev = NULL;
        bool isBST = true;
        inorderBST(root, prev, isBST);
        
        return isBST;
    }
    
    void inorderBST(TreeNode *p, TreeNode *&prev, bool &isBST) {
        if(p) {
            inorderBST(p->left, prev, isBST);
            if(prev && prev->val >= p->val) {
                isBST = false;
                return;
            }
            prev = p;
            inorderBST(p->right, prev, isBST);
        }
    }
};
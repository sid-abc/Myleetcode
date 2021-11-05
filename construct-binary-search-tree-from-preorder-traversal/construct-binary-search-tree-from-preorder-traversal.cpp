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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i = 0;
        TreeNode *root = new TreeNode(preorder[i++]);
        
        TreeNode *p = root;
        stack<TreeNode*> stk;
        while(i < preorder.size()) {
            if(preorder[i] < p->val) {
                TreeNode *t = new TreeNode(preorder[i++]);
                p->left = t;
                stk.push(p);
                p = t;
            }
            else if(preorder[i] > p->val && !stk.empty() && preorder[i] < stk.top()->val) {
                TreeNode *t = new TreeNode(preorder[i++]);
                p->right = t;
                p = t;
            }
            else if(stk.empty()) {
                TreeNode *t = new TreeNode(preorder[i++]);
                p->right = t;
                p = t;
            }
            else {
                p = stk.top();
                stk.pop();
            }
        }
        
        return root;
    }
};
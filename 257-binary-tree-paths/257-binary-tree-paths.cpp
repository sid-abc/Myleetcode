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
    void solve(TreeNode *p, vector<string>& paths, string s) {
        if(!p->left && !p->right) {
            s += to_string(p->val);
            paths.push_back(s);
            return;
        }
        
        s += to_string(p->val) + "->";
        
        if(p->left)
            solve(p->left, paths, s);
        if(p->right)
            solve(p->right, paths, s);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        solve(root, paths, "");
        return paths;
    }
};
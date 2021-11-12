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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        ans.push_back(vector<int> {root->val});
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> v;
            while(size--) {
                TreeNode *p = q.front();
                q.pop();
                if(p->left) {
                    v.push_back(p->left->val);
                    q.push(p->left);
                }
                if(p->right) {
                    v.push_back(p->right->val);
                    q.push(p->right);
                }
            }
            if(!v.empty())
                ans.push_back(v);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
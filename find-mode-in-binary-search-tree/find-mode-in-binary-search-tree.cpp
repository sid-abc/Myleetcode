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
    int currVal = INT_MIN;
    int maxFreq = 0;
    int currFreq = 0;
    vector<int> ans;
    
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
    
    void inorder(TreeNode *p) {
        if(p) {
            inorder(p->left);
            findMax(p->val);
            inorder(p->right);
        }
    }
    
    void findMax(int x) {
        if(x != currVal) {
            currVal = x;
            currFreq = 0;
        }
        currFreq++;
        if(maxFreq < currFreq) {
            maxFreq = currFreq;
            ans.clear();
            ans.push_back(x);
        }
        else if(maxFreq == currFreq)
            ans.push_back(x);
        
    }
};
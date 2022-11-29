class Solution {
public:
    void f(int i, int target, vector<int>& v, vector<int>& c, vector<vector<int>>& res) {
        if(i == c.size()) {
            if(target == 0)
                res.push_back(v);
            return;
        }
        
        if(c[i] <= target) {
            v.push_back(c[i]);
            f(i, target - c[i], v, c, res);
            v.pop_back();
        }
        
        f(i + 1, target, v, c, res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> v;
        f(0, target, v, candidates, res);
        return res;
    }
};
class Solution {
public:
    void f(int ind, int target, vector<int>& v, vector<int>& c, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(v);
            return;
        }
        if(ind == c.size()) {
            if(target == 0)
                res.push_back(v);
            return;
        }
        
        for(int i=ind; i<c.size(); i++) {
            if(i > ind && c[i] == c[i - 1])
                continue;
            if(c[i] > target)
                break;
            v.push_back(c[i]);
            f(i + 1, target - c[i], v, c, res);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> res;
        vector<int> v;
        sort(c.begin(), c.end());
        f(0, target, v, c, res);
        
        return res;
    }
};
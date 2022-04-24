class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(0, nums, dp);
    }
    
    int f(int i, vector<int>& v,vector<int>& dp) {
        if(i == v.size() - 1)
            return 0;
        if(i >= v.size())
            return 1e8;
        int mine = 1e8;
        if(dp[i] != -1)
            return dp[i];
        for(int ind=1; ind<=v[i]; ind++) {
            int e = 1 + f(i + ind, v, dp);
            mine = min(mine, e);
        }
        return dp[i] = mine;
    }
};
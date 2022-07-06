typedef unordered_map<int, int> umap;

class Solution {
public:
    int f(int n, umap& dp) {
        if(n == 1)
            return 0;
        if(n == INT_MAX)
            return 32;
        if(dp.count(n))
            return dp[n];
        if((n & 1) == 0)
            return dp[n] = 1 + f(n >> 1, dp);
        return dp[n] = 1 + min(f(n + 1, dp), f(n - 1, dp));
    }
    
    int integerReplacement(int n) {
        umap dp;
        return f(n, dp);
    }
};
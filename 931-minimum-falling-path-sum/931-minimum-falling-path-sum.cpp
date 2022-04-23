class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int mine = 1e9;
        for(int i=0; i<n; i++)
            mine = min(mine, f(n - 1, i, matrix, dp));
        return mine;
    }
    
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(j < 0 || j >= matrix[0].size())
            return 1e9;
        if(i == 0)
            return matrix[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        int up = matrix[i][j] + f(i - 1, j, matrix, dp);
        int ld = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
        int rd = matrix[i][j] + f(i - 1, j + 1, matrix, dp);
        return dp[i][j] = min(up, min(ld, rd));
    }
};
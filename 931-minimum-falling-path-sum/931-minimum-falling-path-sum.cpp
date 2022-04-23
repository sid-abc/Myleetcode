class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i=0; i<n; i++)
            dp[0][i] = matrix[0][i];
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                int up = matrix[i][j] + dp[i - 1][j];
                int ld = j > 0? matrix[i][j] + dp[i - 1][j - 1]: 1e9;
                int rd = j < n - 1? matrix[i][j] + dp[i - 1][j + 1]: 1e9;
                dp[i][j] = min(up, min(ld, rd));
            }
        }
        int mine = 1e9;
        for(int i=0; i<n; i++)
            mine = min(mine, dp[n - 1][i]);
        return mine;
    }
};
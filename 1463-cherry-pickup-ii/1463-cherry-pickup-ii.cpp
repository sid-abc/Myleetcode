class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return f(0, 0, n - 1, m, n, grid, dp);
    }
    
    int f(int i, int j1, int j2, int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n)
            return -1e8;
        if(i == m-1) {
            if(j1 == j2)
                return grid[i][j1];
            else 
                return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int maxe = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {
                int val = j1 == j2? grid[i][j1]: grid[i][j1] + grid[i][j2];
                val += f(i + 1, j1 + dj1, j2 + dj2, m, n, grid, dp);
                maxe = max(maxe, val);
            }
        }
        return dp[i][j1][j2] = maxe;
    }
};
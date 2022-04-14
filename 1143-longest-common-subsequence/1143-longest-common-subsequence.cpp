class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        if(s.size() > t.size())
    	    return longestCommonSubsequence(t, s);
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
	    int n = dp.size(), m = dp[0].size();
	    for(int i=0; i<n; i++) dp[i][m-1] = 0;
	    for(int i=0; i<m; i++) dp[n-1][i] = 0;
        for(int i=n-2; i>-1; i--) {
		    for(int j=m-2; j>-1; j--) {
			    if(s[i] == t[j])
            	    dp[i][j] = 1 + dp[i + 1][j + 1];
			    else
				    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
		    }
	    }
	    return dp[0][0];
    }
};
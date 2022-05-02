class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n - 1] = true;
        for(int i=n-2; i>-1; i--) {
            for(int ind=1; ind<=nums[i]; ind++) {
                if(i + ind < n) {
                    bool canReach = dp[i + ind];
                    if(canReach) {
                        dp[i] = true;
                        break;
                    }
                }
                else
                    break;
            }
        }
        return dp[0];
    }
};
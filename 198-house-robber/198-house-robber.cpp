class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int ind;
        for(ind=1; ind<nums.size(); ind++) {
            int take = nums[ind]; if(ind > 1) take += dp[ind - 2];
            int notTake = dp[ind - 1];
            dp[ind] = max(take, notTake);
        }
        return dp[ind - 1];
    }
};
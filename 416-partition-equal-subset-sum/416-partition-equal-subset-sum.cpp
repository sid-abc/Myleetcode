class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int x: nums) sum += x;
        if(n == 1 || sum % 2 != 0) return false;
        int k = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
        for(int i=0; i<n; i++) dp[i][0] = true;
        //dp[0][nums[0]] = true;
        
        for(int ind=1; ind<n; ind++) {
            for(int target=1; target<=k; target++) {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if(nums[ind] <= target)
                    take = dp[ind - 1][target - nums[ind]];
                dp[ind][target] = take || notTake;
            }
        }
        return dp[n - 1][k];
    }
};
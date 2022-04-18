class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() < 2) return nums[0];
        vector<int> dp1(nums.size(), -1), dp2(nums.size(), -1);
        int ind1, n = nums.size();
        dp1[0] = nums[0];
        for(ind1=1; ind1<n-1; ind1++) {
            int take = nums[ind1];
            if(ind1 > 1) take += dp1[ind1 - 2];
            int notTake = dp1[ind1 - 1];
            dp1[ind1] = max(take, notTake);
        }
        
        dp2[1] = nums[1];
        int ind2;
        for(ind2=2; ind2<n; ind2++) {
            int take = nums[ind2];
            if(ind2 > 2) take += dp2[ind2 - 2];
            int notTake = dp2[ind2 - 1];
            dp2[ind2] = max(take, notTake);
        }
        
        return max(dp1[ind1 - 1], dp2[ind2 - 1]);
    }
};
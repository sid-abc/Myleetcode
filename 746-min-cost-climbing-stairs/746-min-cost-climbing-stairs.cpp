class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        vector<int> dp(cost.size(), -1);
        return minCost(cost.size()-1, cost, dp);
    }
    int minCost(int ind, vector<int>& cost, vector<int>& dp) {
        if(ind <= 1)
            return cost[ind];
        if(dp[ind] != -1)
            return dp[ind];
        return dp[ind] = min(minCost(ind - 1, cost, dp), minCost(ind - 2, cost, dp)) + cost[ind];
    }
};
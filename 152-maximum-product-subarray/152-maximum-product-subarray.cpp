class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = -1e8, curMax = 1, curMin = 1;
        for(int &x: nums) {
            int temp = x * curMax;
            curMax = max(x, max(x * curMax,  x * curMin));
            curMin = min(x, min(temp, x * curMin));
            res = max(res, curMax);
        }
        return res;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = -1e8, curr = 0;
        for(int x: nums) {
            curr = curr < 0? 0: curr;
            curr += x;
            maxVal = max(maxVal, curr);
        }
        return maxVal;
    }
};
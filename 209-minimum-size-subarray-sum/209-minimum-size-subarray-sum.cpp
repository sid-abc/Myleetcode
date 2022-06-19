//sliding window
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = 1e8, st = 0, end = 0, sum = 0;
        while(end < nums.size()) {
            sum += nums[end];
            while(sum >= target) {
                minLen = min(minLen, end - st + 1);
                sum -= nums[st++];
            }
            end++;
        }
        return minLen != 1e8? minLen: 0;
    }
};
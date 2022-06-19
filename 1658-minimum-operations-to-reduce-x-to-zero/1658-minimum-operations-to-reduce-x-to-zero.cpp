//sliding window
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int &x: nums) sum += x;
        if(sum < x) 
            return -1;
        int target = sum - x;
        int st = 0, end = 0, s = 0, maxLen = -1e8;
        while(end < nums.size()) {
            s += nums[end];
            while(s > target)
                s -= nums[st++];
            if(s == target)
                maxLen = max(maxLen, end - st + 1);
            end++;
        }
        return maxLen != -1e8? nums.size() - maxLen: -1;
    }
};
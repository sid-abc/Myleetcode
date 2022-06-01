class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> degree, left, right;
        int maxFreq = -1e8, minLen = 1e8;
        for(int i=0; i<nums.size(); i++) {
            degree[nums[i]]++;
            if(left.find(nums[i]) == left.end())
                left[nums[i]] = i;
            right[nums[i]] = i;
            if(degree[nums[i]] > maxFreq) {
                maxFreq = degree[nums[i]];
                minLen = right[nums[i]] - left[nums[i]] + 1;
            }
            else if(degree[nums[i]] == maxFreq)
                minLen = min(minLen, right[nums[i]] - left[nums[i]] + 1);
        }
        return minLen;
    }
};
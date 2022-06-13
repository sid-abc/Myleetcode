class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
                 //element index 
        unordered_map<int, int> mp;
        int maxScore = -1e8, sum = 0, j = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(mp.count(nums[i]) && mp[nums[i]] >= j) {
                maxScore = max(maxScore, sum);
                for(; j<=mp[nums[i]]; j++)
                    sum -= nums[j];
                sum += nums[i];
                mp[nums[i]] = i;
            }
            else {
                mp[nums[i]] = i;
                sum += nums[i];
            }
        }
        maxScore = max(maxScore, sum);
        
        return maxScore;
    }
};
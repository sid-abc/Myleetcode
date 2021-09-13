class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int i=0, maxFreq=0;
        while(i < nums.size()) {
            int currFreq = 1;
            while(i+1<nums.size() && nums[i]==1 && nums[i+1]==1) {
                currFreq++;
                i++;
            }
            if(nums[i]==1 && maxFreq<currFreq) {
                maxFreq = currFreq;
            }
            i++;
        }
        return maxFreq;
    }
};
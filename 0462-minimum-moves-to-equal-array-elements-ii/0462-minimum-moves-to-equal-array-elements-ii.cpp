class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, h = nums.size() - 1;
        int res = 0;
        while(l < h) {
            res += abs(nums[l++] - nums[h--]);
        }
        
        return res;
    }
};
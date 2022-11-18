class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mine = *min_element(nums.begin(), nums.end());
        int res = 0;
        
        for(auto x: nums)
            res += x - mine;
        
        return res;
    }
};
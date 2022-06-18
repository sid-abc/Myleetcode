class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;
        int st = 0, end = 0, count = 0, pro = 1;
        while(end < nums.size()) {
            pro *= nums[end];
            while(pro >= k)
                pro /= nums[st++];
            count += end - st + 1;
            end++;
        }
        return count;
    }
};
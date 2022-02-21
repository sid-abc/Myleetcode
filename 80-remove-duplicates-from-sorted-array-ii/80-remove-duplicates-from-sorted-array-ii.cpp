class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        int i = 0;
        for(int x: nums) {
            mp[x]++;
            if(mp[x] < 3)
                nums[i++] = x;
        }
        return i;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x: nums)
            mp[x]++;
        int freq = -1,  val;
        for(auto x: mp) {
            if(x.second > freq) {
                freq = x.second;
                val = x.first;
            }
        }
        return val;
    }
};
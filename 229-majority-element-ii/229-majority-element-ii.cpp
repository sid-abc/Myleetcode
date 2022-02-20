class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        unordered_map<int, int> mp;
        for(int x: nums)
            mp[x]++;
        for(auto x: mp)
            if(x.second > nums.size()/3)
                v.push_back(x.first);
        return v;
    }
};
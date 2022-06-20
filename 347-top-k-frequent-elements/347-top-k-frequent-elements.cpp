class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int &x: nums)
            mp[x]++;
        
        priority_queue<pair<int, int>> pq;
        for(auto &x: mp)
            pq.push(make_pair(x.second, x.first));
        
        vector<int> v;
        while(k--) {
            v.push_back(pq.top().second);
            pq.pop();
        }
        
        return v;
    }
};
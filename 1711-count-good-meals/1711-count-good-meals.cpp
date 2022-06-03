class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        vector<int> t(22);
        for(int i=0; i<22; i++)
            t[i] = pow(2, i);
        
        unordered_map<int, int> mp;
        long long int count = 0;
        for(int x: deliciousness) {
            for(int k: t)
                if(mp[k - x] > 0)
                    count += mp[k - x] ;
            mp[x]++;
        }
        
        return count % 1000000007;
    }
};
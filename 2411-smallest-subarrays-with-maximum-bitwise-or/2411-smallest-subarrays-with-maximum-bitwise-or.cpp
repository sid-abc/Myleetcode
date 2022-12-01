class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& v) {
        vector<int> res(v.size(), 1), ind(32);
        
        for(int i=v.size()-1; i>=0; i--) {
            for(int j=0; j<32; j++) {
                if(v[i] & (1 << j))
                    ind[j] = i;
                res[i] = max(res[i], ind[j] - i + 1);
            }
        }
        
        return res;
    }
};
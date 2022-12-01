class Solution {
public:
    int xorAllNums(vector<int>& v1, vector<int>& v2) {
        if(v1.size() < v2.size())
            return xorAllNums(v2, v1);
        
        if(v1.size() % 2 == 0 && v2.size() % 2 == 0)
            return 0;
        if(v1.size() % 2 == 1 && v2.size() % 2 == 1) {
            int xo = 0;
            for(auto x: v1) xo ^= x;
            for(auto x: v2) xo ^= x;
            return xo;
        }
        if(v1.size() % 2 == 1 && v2.size() % 2 == 0) {
            int xo = 0;
            for(auto x: v2) xo ^= x;
            return xo;
        }
        int xo = 0;
        for(auto x: v1) xo ^= x;
        return xo;
    }
};
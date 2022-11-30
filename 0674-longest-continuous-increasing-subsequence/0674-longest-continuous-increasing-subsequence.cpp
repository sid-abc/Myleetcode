class Solution {
public:
    int findLengthOfLCIS(vector<int>& v) {
        int i = 0, j = 1, max_len = 1;
        while(j < v.size()) {
            if(v[j] <= v[j - 1]) {
                i = j, j++;
                continue;
            }
            max_len = max(max_len, j - i + 1);
            j++;
        }
        
        return max_len;
    }
};
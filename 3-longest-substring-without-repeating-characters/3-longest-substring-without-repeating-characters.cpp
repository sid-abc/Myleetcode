class Solution {
public:
    int lengthOfLongestSubstring(string s) {
                   //char   index
        unordered_map<char, int> mp;
        int maxLen = -1e8, i, j = 0;
        
        for(i=0; s[i]!='\0'; i++) {
            if(mp.count(s[i]) && mp[s[i]] >= j) {
                maxLen = max(maxLen, i - j);
                j = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
        }
        maxLen = max(maxLen, i - j);
        
        return maxLen;
    }
};
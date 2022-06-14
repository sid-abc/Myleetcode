// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//                    //char   index
//         unordered_map<char, int> mp;
//         int maxLen = -1e8, i, j = 0;
        
//         for(i=0; s[i]!='\0'; i++) {
//             if(mp.count(s[i]) && mp[s[i]] >= j) {
//                 maxLen = max(maxLen, i - j);
//                 j = mp[s[i]] + 1;
//             }
//             mp[s[i]] = i;
//         }
//         maxLen = max(maxLen, i - j);
        
//         return maxLen;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int st = 0, end = 0, maxLen = 0;
        
        while(s[end] != '\0') {
            mp[s[end]]++;
            while(mp[s[end]] > 1)
                mp[s[st++]]--;
            maxLen = max(maxLen, end - st + 1);
            end++;
        }
        
        return maxLen;
    }
};
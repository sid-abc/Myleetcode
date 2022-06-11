class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int count = 0, odd = 0;
        for(auto x: s)
            mp[x]++;
        for(auto x: mp) {
            if(x.second % 2 == 0)
                count += x.second;
            else {
                count += x.second - 1;
                odd = 1;
            }
        }
        return count + odd;
    }
};
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int count = 0;
        
        for(auto x: words) {
            string rev = x;
            reverse(rev.begin(), rev.end());
            if(mp[rev] > 0) {
                count += 4;
                mp[rev]--;
            }
            else 
                mp[x]++;
        }
        
        for(auto x: mp) {
            if(x.second > 0 && x.first[0] == x.first[1]) {
                count += 2;
                break;
            }
        }
        
        return count;
    }
};
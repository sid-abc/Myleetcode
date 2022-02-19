class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        return isPalindrome(to_string(x));
    }
    
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r])
                return false;
            l++; r--;
        }
        return true;
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while(s[i] == 32) i--;
        int j = i;
        while(j > -1 && s[j] != 32) j--;
        j++;
        
        return i - j + 1;
    }
};
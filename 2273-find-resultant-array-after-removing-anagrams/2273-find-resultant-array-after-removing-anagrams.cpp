class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        
        for(auto &x: mp)
            if(x.second != 0)
                return false;
        
        return true;
    }
    
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> v;
        v.push_back(words[0]);
        int j = 1;
        for(int i=1; i<words.size(); i++) {
            if(!isAnagram(words[i - j], words[i])) {
                v.push_back(words[i]);
                j = 1;
            }
            else
                j++;
        }
        
        return v;
    }
};
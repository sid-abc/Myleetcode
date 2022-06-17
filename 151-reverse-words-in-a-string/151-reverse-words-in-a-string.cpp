class Solution {
public:
    string reverseWords(string s) {
        string w;
        stack<string> stk;
        int i = 0;
        bool f = false;
        s.push_back(' ');
        for(int i=0; s[i]!='\0'; i++) {
            if(s[i] == ' ' && f) {
                stk.push(w + ' ');
                w = "";
                f = false;
            }
            else if(s[i] != ' ') {
                w.push_back(s[i]);
                f = true;
            }
        }
        
        string rev;
        while(!stk.empty()) {
            rev += stk.top();
            stk.pop();
        }
        rev.pop_back();
        
        return rev;
    }
};
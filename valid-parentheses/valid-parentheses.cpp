class Solution {
public:
    bool isValid(string s) {
        stack <char> stk;
        for(int i=0;s[i]!='\0';i++) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                stk.push(s[i]);
            else if(stk.empty())
                return false;
            else if(s[i]==')' && stk.top()=='(' || s[i]=='}' && stk.top()=='{' || s[i]==']' && stk.top()=='[') { 
                stk.pop();
            }
            else
                return false;
        }
        if(stk.empty())
            return true;
        else 
            return false;
    }
};
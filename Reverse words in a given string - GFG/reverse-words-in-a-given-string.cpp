//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S)  { 
        stack<string> stk;
        string a;
        for(char c: S) {
            if(c != '.') a.push_back(c);
            else stk.push(a), a.clear();
        }
        stk.push(a);
        
        string res = "";
        while(!stk.empty()) {
            res += stk.top();
            res.push_back('.'), stk.pop();
        }
        res.pop_back();
        
        return res;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
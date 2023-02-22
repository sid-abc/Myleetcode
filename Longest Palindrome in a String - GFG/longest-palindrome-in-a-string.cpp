//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin(string s) {
        string res = s.substr(0, 1);
        int mx = 1;
        for(int i=0; i<s.size(); i++) {
            int l = i - 1, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r])
                l--, r++;
            l++, r--;
            if(l >= 0 && r < s.size() && r - l + 1 > mx)
                mx = r - l + 1, res = s.substr(l, mx);
                
            
            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r])
                l--, r++;
            l++, r--;
            if(l >= 0 && r < s.size() && r - l + 1 > mx)
                mx = r - l + 1, res = s.substr(l, mx);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
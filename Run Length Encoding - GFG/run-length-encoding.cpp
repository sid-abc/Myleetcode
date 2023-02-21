//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string s) {     
    string res;
    int i = 0, j = 0;
    while(j < s.size()) {
        if(s[i] == s[j]) j++;
        else {
            res.push_back(s[i]), res.push_back(j - i + '0');
            i = j;
        }
    }
    res.push_back(s[i]), res.push_back(j - i + '0');
    
    return res;
}     
 

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef long long ll;
const ll mod = 1e9 + 7;
class Solution{
	public:
		int nthPoint(int n){
		    vector<int> dp(n + 1);
		    dp[0] = 1, dp[1] = 1;
		    
		    for(int i=2; i<=n; i++) {
		        dp[i] = dp[i - 1] + dp[i - 2];
		        dp[i] %= mod;
		    }
		    
		    return dp.back();
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
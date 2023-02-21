//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

typedef long long ll;
class Solution {
    public:
    vector<long long> nextLargerElement(vector<long long>& arr, int n) {
        vector<ll> v(n);
        stack<ll> stk;
        stk.push(arr.back());
        v.back() = -1;
        for(int i=n-2; i>=0; i--) {
            while(!stk.empty() && arr[i] >= stk.top())
                stk.pop();
            v[i] = stk.empty()? -1: stk.top();
            stk.push(arr[i]);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
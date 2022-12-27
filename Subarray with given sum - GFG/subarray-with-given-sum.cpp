//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>v, int n, long long s)
    {
        int st = 0, end = 0;
        long long sum = 0;
        vector<int> res;
        while(end < n) {
            sum += v[end];
            while(sum > s && st < end)
                sum -= v[st++];
            if(sum == s) {
                res.push_back(st + 1), res.push_back(end + 1);
                return res;
            }
            end++;
        }
        res.push_back(-1);
        return res;
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
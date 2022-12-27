//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N) {
        sort(arr, arr + N);
        int cnt = 1, max_len = 1, j = 0;
        for(int i=1; i<N; i++) {
            if(arr[i] - arr[j] == 1)
                cnt++, j = i;
            else if(arr[i] != arr[i - 1])
                cnt = 1, j = i;
            max_len = max(max_len, cnt);
       }
       
       return max_len;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
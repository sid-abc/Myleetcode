//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
       for(auto x: nums)
            mp[x]++;
        
        vector<pair<int,int>> v;
        for(auto x: mp)
            v.push_back(x);
        
        sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) -> bool {
            if(a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
        });
        
        vector<int> res(k);
        for(int i=0; i<k; i++)
            res[i] = v[i].first;
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool f(int src, vector<bool>& vis, vector<int> adj[]) {
        queue<pair<int,int>> q;
        q.push({src, -1});
        vis[src] = true;
        while(!q.empty()) {
            int node = q.front().first, parent = q.front().second;
            q.pop();
            for(auto x: adj[node]) {
                if(!vis[x])
                    vis[x] = true, q.push({x, node});
                else if(x != parent)
                    return true;
            }
        }
        return false;
    }
    
    bool isCycle(int n, vector<int> adj[]) {
        vector<bool> vis(n, false);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(f(i, vis, adj)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
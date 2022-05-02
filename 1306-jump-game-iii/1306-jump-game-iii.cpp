class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);
        return f(start, n, arr, vis);
    }
    
    bool f(int i, int n, vector<int>& v,  vector<bool>& vis) {
        if(i < 0 || i >=n || vis[i])
            return false;
        if(v[i] == 0)
            return true;
        vis[i] = true;
        bool right = f(i + v[i], n, v, vis);
        bool left = f(i - v[i], n, v, vis);
        return right || left;
    }
};
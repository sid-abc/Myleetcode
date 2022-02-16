class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(first(nums, target));
        res.push_back(last(nums, target));
        return res;
    }
    
    int first(vector<int>& v, int x) {
        int l = 0, h = v.size() - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if((mid == 0 || x > v[mid - 1]) && v[mid] == x)
                return mid;
            else if(x > v[mid])
                l = mid + 1;
            else 
                h = mid - 1;
        }
        return - 1;
    }
    
    int last(vector<int>& v, int x) {
        int l = 0, h = v.size() - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if((mid == v.size()-1 || x < v[mid + 1]) && x == v[mid])
                return mid;
            else if(x < v[mid])
                h = mid - 1;
            else 
                l = mid + 1;
        }
        return -1;
    }
};
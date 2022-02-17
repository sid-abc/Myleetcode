class Solution {
public:
    int searchInsert(vector<int>& nums, int key) {
        int l,mid,h;
        l=0;
        h=nums.size()-1;
        while(l<=h) {
            mid=(l+h)/2;
            if(key==nums[mid])
                return mid;
             else if(key<nums[mid])
                h=mid-1;
             else
                l=mid+1;
         }
        return h+1;

    }
};
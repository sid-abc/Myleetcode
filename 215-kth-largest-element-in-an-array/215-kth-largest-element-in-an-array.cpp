class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=0; i<k; i++) {
            int k;
            for(int j=k=i; j<nums.size(); j++)
                if(nums[j] > nums[k])
                    k = j;
            swap(nums[i], nums[k]);
        }
        return nums[k - 1];
    }
};
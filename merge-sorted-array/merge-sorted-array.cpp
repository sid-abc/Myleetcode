class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        while(i<m && j<n) {
            if(nums1[i] < nums2[j])
                i++;
            else {
                for(int k=m;k>i;k--) 
                    nums1[k] = nums1[k-1];
                nums1[i++] = nums2[j++];
                m++;
            }
        }
        
        for(; i<m;i++);
        
        for(; j<n;)
            nums1[i++] = nums2[j++];   
    }
};
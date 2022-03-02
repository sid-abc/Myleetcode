class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int red = 0, white = 0, blue = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0)
                red++;
            else if(nums[i] == 1)
                white++;
            else 
                blue++;
        }
        int i = 0;
        while(i < red)
            nums[i++] = 0;
        white += red;
        while(i < white)
            nums[i++] = 1;
        while(i < n)
            nums[i++] = 2;
    }
};
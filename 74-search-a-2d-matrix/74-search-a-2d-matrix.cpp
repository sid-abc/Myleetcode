class Solution {
public:
    bool searchRow(vector<vector<int>>& matrix, int row, int target) {
        int n = matrix[0].size();
        int l = 0, h = n - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(matrix[row][mid] == target)
                return true;
            else if(target < matrix[row][mid])
                h = mid - 1;
            else 
                l = mid + 1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, h = m - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(target >= matrix[mid][0] && target <= matrix[mid][n - 1])
                return searchRow(matrix, mid, target);
            else if(target < matrix[mid][0])
                h = mid - 1;
            else 
                l = mid + 1;
        }
        return false;
    }
};
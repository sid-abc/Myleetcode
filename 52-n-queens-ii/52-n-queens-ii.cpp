class Solution {
public:
    bool isSafe(int row, int col, int n, vector<vector<bool>>& board) {
        int dupRow = row, dupCol = col;
        while(row > -1 && col > -1) {
            if(board[row][col])
                return false;
            row--; col--;
        }
        row = dupRow, col = dupCol;
        while(col > -1) {
            if(board[row][col])
                return false;
            col--;
        }
        row = dupRow, col = dupCol;
        while(row < n && col > -1) {
            if(board[row][col])
                return false;
            row++; col--;
        }
        return true;
    }
    
    void solve(int col, int n, int& count, vector<vector<bool>>& board) {
        if(col == n) {
            count++;
            return;
        }
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, n, board)) {
                board[row][col] = true;
                solve(col + 1, n, count, board);
                board[row][col] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        int count = 0;
        solve(0, n, count, board);
        return count;
    }
};
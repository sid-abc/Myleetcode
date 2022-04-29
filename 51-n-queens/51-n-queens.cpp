class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string>& board) {
        int dupRow = row, dupCol = col;
        while(row > -1 && col > -1) {
            if(board[row][col] == 'Q')
                return false;
            row--; col--;
        }
        row = dupRow, col = dupCol;
        while(col > -1) {
            if(board[row][col] == 'Q')
                return false;
            col--;
        }
        row = dupRow, col = dupCol;
        while(row < n && col > -1) {
            if(board[row][col] == 'Q')
                return false;
            row++; col--;
        }
        return true;
    }
    
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& res) {
        if(col == n) {
            res.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(col + 1, n, board, res);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++)
            board[i] = s;
        solve(0, n, board, res);
        return res;
    }
};
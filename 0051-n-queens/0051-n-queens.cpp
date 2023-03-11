class Solution {
public:
    bool isSafe(int row,int col,vector<string>&board,int n){
        int dr=row;
        int dc=col;
        // left side check in row
        while(dc>=0){
            if(board[dr][dc]=='Q'){
                return false;
            }
            dc--;
        }
        // check upper diagonal
        dr=row;
        dc=col;
        while(dr>=0 && dc>=0){
            if(board[dr][dc]=='Q'){
                return false;
            }
            dr--; dc--;
        }
        dr=row; dc=col;
        while(dr<n && dc>=0){
            if(board[dr][dc]=='Q'){
                return false;
            }
            dr++; dc--;
        }
        return true;
    }
    
    void solve(int col, vector<string>&board, vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        vector<string> board;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        solve(0,board,ans,n);
        return ans;
    }
};
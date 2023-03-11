class Solution {
public:
    bool isSafe(int row,int col,vector<string>&board,int n){
        int dr= row, dc= col;
        // left
        while(dc>=0){
            if(board[dr][dc]=='Q'){
                return false;
            }
            dc--;
        }
        dr= row, dc=col;
        //upper diagonal
        while(dc>=0 && dr>=0){
            if(board[dr][dc]=='Q'){
                return false;
            }
            dc--;  dr--;
        }
        dr= row, dc=col;
        //lower diagonal
        while(dc>=0 && dr<n){
            if(board[dr][dc]=='Q'){
                return false;
            }
            dc--;  dr++;
        }
        return true;
        
    }
    
    void solve(vector<string>&board,vector<vector<string>>&ans, int n, int col ){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(board,ans,n,col+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board;
        for(int i=0;i<n;i++)    board.push_back(s);
        
        solve(board,ans,n,0);
        return ans;
    }
};
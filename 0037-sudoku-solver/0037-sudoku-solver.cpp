class Solution {
public:
    bool helper(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){ 
                    for(char k='1';k<='9';k++){
                        if(isValid(i,j,k,board)){
                            board[i][j]=k;
                            if(helper(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    bool isValid(int r,int c,char no,vector<vector<char>>& board ){
        
        for(int i=0;i<9;i++){
            if(board[i][c]==no){
                return false;
            }
            
            if(board[r][i]==no){
                return false;
            }
            
            if(board[3*(r/3)+ i/3][3*(c/3)+ i%3]== no){
                return false;
            }
        }
        return true;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        helper(board);
        
        // return board;
        
    }
};
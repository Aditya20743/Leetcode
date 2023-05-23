class Solution {
public:
    
    void reveal(vector<vector<char>>& board, int r,int c){
        int m= board.size();
        int n=board[0].size();
        
        if(r< 0 || c<0 || r>=m || c>=n) return;
        
        if(board[r][c] =='E'){
            int count=0;
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr=r+i;
                    int nc=c+j;
                    if(nr>= 0 && nc>=0 && nr<m && nc<n && !(nr==r && nc==c)){
                        if(board[nr][nc]=='M'){
                            count++;
                        }
                    }
                }
            }
            
            if(count>0){
                board[r][c]='0'+count;
            }
            else{
                board[r][c]='B';
                    for(int i=-1;i<=1;i++){
                        for(int j=-1;j<=1;j++){
                            int nr=r+i;
                            int nc=c+j;
                            if(nr>= 0 && nc>=0 && nr<m && nc<n && !(nr==r && nc==c)){
                                reveal(board,nr,nc);
                            }
                        }
                    }
            }
        }
        
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m= board.size();
        int n=board[0].size();
        
        int r= click[0];
        int c= click[1];
        
        if(board[r][c]=='M'){
            board[r][c]='X';
            return board;
        }
        
        reveal(board,r,c);
        return board;
        
        
    }
};
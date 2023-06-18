class Solution {
public:
    vector<int> xdir={-1,0,1,0};
    vector<int> ydir={0,-1,0,1};
    
    bool solve(int r,int c,vector<vector<char>>& board, string word, int idx, vector<vector<int>>& vis){
        int m= board.size();
        int n= board[0].size();
        
        vis[r][c]=1;
        
        
        if(idx== word.size()){
            return true;
        }
        
        for(int i=0;i<4;i++){
            int nr= r+ xdir[i];
            int nc= c+ ydir[i];
            
            if(nr>=0 && nc>=0 && nr<m && nc<n ){
                if(word[idx]== board[nr][nc] && vis[nr][nc]==0){
                    if(solve(nr,nc,board, word,idx+1,vis)){
                        return true;
                    }
                }
            }
        }
        vis[r][c]=0;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m= board.size();
        int n= board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,board, word, 1,vis)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
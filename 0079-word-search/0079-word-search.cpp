class Solution {
public:
    vector<int> dir = {-1,0,1,0,-1};
    
    bool functionToFindWord(int i,int j, string&word, vector<vector<char>>&board, int idx, vector<vector<int>>&vis){
        int m = board.size();
        int n =board[0].size();
        
        
        if(idx == word.size()){
            return true;
        }
        
        for(int k=0;k<4;k++){
            int ni = i+ dir[k];
            int nj = j+ dir[k+1];
            
            if(ni>=0 && ni<m && nj>=0 && nj<n && vis[ni][nj]== -1){
                if(board[ni][nj]== word[idx]){
                    vis[ni][nj] = 1;
                    if(functionToFindWord(ni,nj,word,board,idx+1,vis) == true){
                        return true;
                    }
                    vis[ni][nj] = -1;
                }
            }
        }
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n =board[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n, -1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = 1;
                    if(functionToFindWord(i,j,word,board,1, vis) == true){
                        return true;
                    }
                    vis[i][j] = -1;
                }
            }
        }
        return false;
    }
};
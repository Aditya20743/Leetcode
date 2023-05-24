class Solution {
public:
    bool check(vector<int> v){
        for(auto it: v){
            // cout<<it<<" ";
            if(it>1)    return false;
        }
        
        return true;
    }
    bool sub(vector<vector<char>>& board, int i,int j){
        unordered_map<int,int> mp;
        for(int x=i;x<i+3;x++){
            for(int y=j;y<j+3;y++){
                if(board[x][y]!= '.'){
                    mp[board[x][y]-'0']++;
                    if(mp[board[x][y]-'0']>1 ){
                        return false;
                    }
                }
            }
        }
        // for(auto it: mp){
        //     cout<<"ele-"<<it.first<<" "<<it.second<<" ";
        // }
        // cout<<endl;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n= board.size();
        
        
        
        
        for(int i=0;i<n;i++){
            
            vector<int> row(n+1,0);
            for(int j=0;j<n;j++){
                if(board[i][j]!= '.')
                row[board[i][j]-'0']++;
            }
            if(check(row)==false){
                return false;
            }
        }
        
        for(int c=0;c<n;c++){
            vector<int> col(n+1,0);
            for(int r=0;r<n;r++){
                if(board[r][c]!= '.')
                col[board[r][c]-'0']++;
            }
            // for(auto it: col){
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            if(check(col)==false){
                return false;
            }
            
        }
        
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                if(sub(board, i, j)==false){
                    return false;
                }
            }
        }
        return true;
        
    }
};
// [[".",".",".",".","5",".",".","1","."]
// [".","4",".","3",".",".",".",".","."],
// [".",".",".",".",".","3",".",".","1"],
// ["8",".",".",".",".",".",".","2","."],
// [".",".","2",".","7",".",".",".","."],
// [".","1","5",".",".",".",".",".","."],
// [".",".",".",".",".","2",".",".","."],
// [".","2",".","9",".",".",".",".","."],
// [".",".","4",".",".",".",".",".","."]]
class Solution {
public:
    int n;
    pair<int,int> cord(int val){
        int rt= (val-1)/n;
        int rb= (n-1 -(rt));
        
        int col= (val-1)%n;
        if((n%2==1 && rb%2== 1) || (n%2==0 && rb%2==0)){
            col=(n-1)-col;
        }
        return make_pair(rb,col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n= board.size();
        vector<vector<bool> > vis(n,vector<bool>(n,false));
        queue<int> q;
        q.push(1);
        vis[n-1][0]=true;
        int steps=0;
        
        while(!q.empty()){
            int t= q.size();
            for(int i=0;i<t;i++){
                int x= q.front();
                q.pop();
                if(x== n*n) return steps;
                for(int j=1;j<=6;j++){
                    int val = x+j;
                    if(val> n*n)    break;
                    
                    pair<int,int> p = cord(val);
                    int r= p.first;
                    int c= p.second;
                    
                    if(vis[r][c]==false){
                        vis[r][c]=true;
                        if(board[r][c]==-1) q.push(val);
                        else
                            q.push(board[r][c]);
                    }
                    
                }
                
            }
            steps++;
            
        }
        return -1;
    }
};
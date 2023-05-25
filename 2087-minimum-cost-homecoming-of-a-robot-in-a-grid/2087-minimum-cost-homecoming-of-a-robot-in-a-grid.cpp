class Solution {
public:
    int helper(int r,int c, int dx,int dy, vector<int>& rowCosts, vector<int>& colCosts){
        int m= rowCosts.size();
        int n= colCosts.size();
        
        if(r>= m || c>=n || r<0 || c<0) return 1e8;
        
        if(r== dx && c== dy)  return 0;
        
        int up=1e8, down =1e8, left= 1e8, right= 1e8;
        
        if(r-1>=0)
        up =   helper(r-1, c, dx, dy, rowCosts, colCosts)+ rowCosts[r-1];
        if(r+1<m)
        down = helper(r+1, c, dx, dy, rowCosts, colCosts)+ rowCosts[r+1];
        if(c-1>=0)
        left = helper(r, c-1, dx, dy, rowCosts, colCosts)+ colCosts[c-1];
        if(c+1<n)
        right= helper(r, c+1, dx, dy, rowCosts, colCosts)+ colCosts[c+1];
        
        return min(min(up,left),min(down,right));
        
    }
    
    
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int m= rowCosts.size();
        int n= colCosts.size();
        
        int r= startPos[0];
        int c= startPos[1];
        
        int dx= homePos[0];
        int dy= homePos[1];
        
        int val=0;
        while(abs(dy-c)!=0){
            if(dy>c){
                val+= colCosts[++c];
            }
            else {
                val+= colCosts[--c];
            }
        }
        while(abs(dx-r)!=0){
            if(dx>r){
                val+= rowCosts[++r];
            }
            else {
                val+= rowCosts[--r];
            }
        }
        return val;
        // return helper(r,c,dx,dy, rowCosts, colCosts);
    }
};
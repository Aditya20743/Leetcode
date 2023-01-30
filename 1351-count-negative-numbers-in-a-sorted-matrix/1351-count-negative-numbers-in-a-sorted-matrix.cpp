class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int c=0;
        for(int i=0;i<n;i++){
            int l=0, r=m-1;
            while(l<=r){
                int m= l+(r-l)/2;
                if(grid[i][m]<0) {{if(grid[i][m]==0) c--; }  r=m-1;}
                else if(grid[i][m]>=0)   l=m+1;
            }
            c+= m-l;
            cout<<c<<endl;
        }
        return c;
    }
};
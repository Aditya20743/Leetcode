class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        
        for(int i=0;i<queries.size();i++){
            int r1=queries[i][0];
            int r2=queries[i][2];
            int c1=queries[i][1];
            int c2=queries[i][3];
            
            for(int j=c1;j<=c2;j++){
                ans[r1][j]++;
                if(r2<n-1)
                ans[r2+1][j]--;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>0) 
                    ans[i][j]+=ans[i-1][j];
            }
        }
        return ans;
    }
};
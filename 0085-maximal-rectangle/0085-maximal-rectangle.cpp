class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=i, l, collen = m;k<n && matrix[k][j]=='1';k++){
        
                    for(l=j;l<m && matrix[k][l]=='1';l++);
                    
                    collen = min(collen , l-j);
                    ans = max(ans , (k-i+1)*(collen));

                }
            }
        }
        
        return ans;
    }
};
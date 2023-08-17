class Solution {
public:
//     void setZeroes(vector<vector<int>>& matrix) {
        
//         // O(nm) time complexity && O(n+m) Space Complexity
        
//         int m= matrix.size();
//         int n= matrix[0].size();
//         vector<int> row(m,1), col(n,1);
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==0){
//                     row[i]=0;
//                     col[j]=0;
//                 }
//             }
//         }
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(row[i]==0 || col[j]==0){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
//         // return matrix;
//     }
    
    void setZeroes(vector<vector<int>>& matrix) {
        
        // O(mn) time complexity && O(1) Space Complexity
        
        int m= matrix.size();
        int n= matrix[0].size();
        int row0=1, col0=1;
        // row0=0 states all values should be zero in 0th row 
        // col0=0 states all values should be zero in 0th col
        
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                col0=0;
            }
        }
        for(int j=0;j<n;j++){
            if(matrix[0][j]==0){
                row0=0;
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    // whenever we find zero, mark [i][0] and [0][j] as zero then 
                    // then wherever [i][0]=0 or [0][j]=0 mark [i][j]=0;
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            if(col0==0){
                matrix[i][0]=0;
            }
        }
        for(int j=0;j<n;j++){
            if(row0==0){
                matrix[0][j]=0;
            }
        }
        // return matrix;
    }
    
};
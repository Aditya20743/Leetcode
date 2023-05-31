class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int n= matrix[0].size();
        
        int row= m-1;
        int col= 0;
        
        while(row>=0 && col< n){
            
            while(row>=0 && col< n && matrix[row][col] > target){
                row--;
            }
            while(row>=0 && col< n && matrix[row][col]< target){
                col++;
            }
            if(row>=0 && col< n && matrix[row][col]==target)    return true;
        }
        return false;
    }
};
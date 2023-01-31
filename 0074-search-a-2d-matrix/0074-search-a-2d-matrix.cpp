class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int rl=0, rr=n-1;
        int cu=0, cd=n-1;
        
        while( cu<= m-1  && rr> -1){
            if(matrix[cu][rr]==target)  return true;
            else if(matrix[cu][rr]> target) rr--;
            else
                cu++;
        }
        return 
            false;
        
//         while(cu<cd){
//             int cm= cu+ (cd-cu)/2;
//             if(matrix[cm][rl]<target)   cu= cm;
//             else if(matrix[cm][rl]> target) cd= cm-1;
//             else 
//                 return true;
//         }
        
//         while(rl<=rr){
//             int rm= rl+ (rr-rl)/2;
//             if(matrix[cu][rm]>target)   rr= rm-1;
//             else if(matrix[cu][rm]< target) rl= rm+1;
//             else 
//                 return true;
//         }
//         return false;
    }
};
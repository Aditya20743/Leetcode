class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n));
        
        int x=1;
        int top= 0, left=0 , right= n-1, bottom= n-1;
        int direction =1;
        
        while(left<= right && top<= bottom){
            
            if(direction ==1){   
                for(int i=left;i<=right;i++)   v[top][i]= x++;
                top++;
                direction++;
            } 
            else if(direction==2){
                for(int i=top;i<=bottom;i++)    v[i][right]= x++;
                right--;
                direction++;
            }
            else if(direction==3){
                for(int i=right;i>= left;i--)   v[bottom][i]= x++;
                bottom--;
                direction++;
            }
            else if(direction==4){
                for(int i=bottom;i>=top;i--)    v[i][left]=x++;
                left++;
                direction=1;
            }
        }
        return v;
    }
};
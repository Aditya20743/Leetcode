class Solution {
public:
    bool judgeSquareSum(int c) {
        unsigned long long i=0, j=sqrt(c);
        while(i<=j){
            if(i*i + j*j == c)  return true;
            else if(i*i + j*j > c)  j--;
            else 
                i++;
        }
        return false;
    }
    
};
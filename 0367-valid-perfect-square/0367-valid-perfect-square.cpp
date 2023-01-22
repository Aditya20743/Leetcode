class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l=0, r=num;
        while(l<=r){
            long long m= (l+r)/2;
            if(m*m >num)    r=m-1;
            else if(m*m <num)   l=m+1;
            else    
                return true;
        }
        return false;
    }
};
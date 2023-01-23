class Solution {
public:
    int mySqrt(int x) {
        long long l=1, r=x;
        while(r>=l){
            long long m=(l+r)/2;
            if(m*m> x){
                r=m-1;
            }
            else if(m*m< x){
                l=m+1;
            }
            else
                return m;
        }
        return l-1;
    }
};
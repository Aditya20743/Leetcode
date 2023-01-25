class Solution {
public:
    int arrangeCoins(int n) {
        // 1,2,3,4,5,6,
        // n(n+1)/2
        long long l=1,r=n;
        while(l<=r){
            long long m= l+(r-l)/2;
            if(m*(m+1)/2 > n)   r=m-1;
            else if(m*(m+1)/2<n)  l=m+1;
            else return m;
        }
        return r;
    }
};
class Solution {
public:
    int totalMoney(int n) {
        if(n<=7)
            return (n*(n+1))/2;
        
        vector<unsigned long long> dp(1001,0);
        vector<long long > x(8,0);
        for(int i=0;i<=7;i++){
            x[i]=i;
        }
        for(int i=0;i<=7;i++){
            dp[i]= (i*(i+1))/2;
        }
        int c=1;
        for(int i=8;i<=1000;i++){
            if(i%7!=0)  
            dp[i]= dp[i-1]+x[i%7]+c;
            else{
                dp[i]= dp[i-1]+x[7]+c;
            }
            c=i/7;
        }
        return dp[n];
        
    }
};
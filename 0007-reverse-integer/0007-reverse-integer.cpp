class Solution {
public:
    int reverse(int x) {
        int y= abs(x);
        int ans=0;
        while(y>0){
            if(ans>INT_MAX/10 || ans<INT_MIN/10)  return 0;
            int r=y%10;
            y= y/10;
            ans= ans*10+ r;
            
        }
        if(x<0){
            ans= -ans;
        }
        
        // cout<<ans<<endl;
        return ans;
    }
};
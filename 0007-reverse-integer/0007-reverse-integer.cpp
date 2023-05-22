class Solution {
public:
    int reverse(int x) {
        long long y= abs(x);
        long long ans=0;
        while(y>0){
            int r=y%10;
            y= y/10;
            ans= ans*10+ r;
        }
        if(x<0){
            ans= -ans;
        }
        
        long long upper= pow(2,31)-1;
        long long lower= - pow(2,31);
        if(ans> upper){
            ans=0;
        }
        else if(ans< lower){
            ans=0;
        }
        // cout<<ans<<endl;
        return (int)ans;
    }
};
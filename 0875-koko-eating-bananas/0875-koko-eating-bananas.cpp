class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // long long sum=0;
        // for(auto it: piles){
        //     sum+= it;
        // }
        long long l=1,r=*max_element(piles.begin(),piles.end());
        long long m=0;
        while(l<=r){
            m= l+ (r-l)/2;
            long long nh=0;
            for(auto it: piles){
                double x = it;
                nh+= ceil(x/m);
            }
            if(nh>h){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        //ut<<m<<" ";
        // int mh=0;
        // for(int i=m-1;i>=1;i--){
        //     for(auto it: piles){
        //         long double x= it;
        //         mh+= ceil(x/i);
        //     }
        //     if(mh> h)   return i+1;  
        //     mh=0;
        // }
        return l;
    }
};
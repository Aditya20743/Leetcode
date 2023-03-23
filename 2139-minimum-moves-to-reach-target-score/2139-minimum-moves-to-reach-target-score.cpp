class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int d=target;
        int ans=0;
        
        while(maxDoubles){
            if(d==0)    return ans-1;
            if(d%2==1){
                ans++;
                d--;
            }
            else {
                if(d!=0){
                    d=d/2;
                    ans++;
                    maxDoubles--;
                }
                
            }
        }
        return ans+ d-1;
        
        
        
        
        // while(d!=0){
        //     while(maxDoubles>0 && d%2==0 && d!=0) {
        //         maxDoubles--;
        //         d= d/2;
        //         ans++;
        //     }
        //     if((d%2 || maxDoubles==0)&& d!=0 ){
        //         d--;
        //         ans++;
        //     }
        // }
        // return ans-1;
    }
};
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        int firstmin= max(n-2*limit, 0);
        int firstmax= min(limit, n);
        
        for(int i= firstmin;i<= firstmax;i++){
            int secondmin= max(0, n-i-limit);
            int secondmax= min(limit, n-i-0);
            
            ans+= secondmax- secondmin +1;
        }
        
        return ans;
    }
};
class Solution {
public:
    int rev(int a){
        int ans=0;
        while(a){
            ans= ans*10+ a%10;
            a= a/10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        // 42 - 24 = 18
        // 11 - 11 = 0
        // 1 - 1  = 0
        // 97 - 79 = 18
        
        // 13 - 31 = -18
        // 10 - 01 = 9
        // 35 - 53 = -18
        // 24 - 42 = -18
        // 76 - 67 = 9
        
        
        int mod= 1e9+7;
        unordered_map<int,int> mp;
        
        int ans=0;  
        
        for(auto it: nums){
            int diff = it - rev(it);
            if(mp.find(diff) != mp.end()){
                ans = (ans + mp[diff])%mod;

            } 
            mp[diff]++;
        }
        
        // long long ans=0;
        // for(auto it: mp){
        //     long long t= it.second;
        //     if(t>=2){
        //         ans= ans+ (((t%mod)*(t-1)%mod)%mod/2)%mod;
        //     }
        // }
        return ans;
        
    }
};
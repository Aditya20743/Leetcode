class Solution {
public:
    int mod= 1e9+7;
    int helper(int idx,string&s ,int k, vector<int>&dp){
        if(idx== s.size())  return 1;
        if(s[idx]=='0')     return 0;
        if(dp[idx]!= -1)  return dp[idx];
        
        long long num=0, ans=0;
        for(int i= idx;i< s.size();i++){
            num= num*10+ (s[i]-'0');
            if(num>k){
                break;
            }
            ans= (ans+helper(i+1, s,k,dp))%mod;
        }
       return dp[idx]= ans; 
    }
    int numberOfArrays(string s, int k) {
        int n=s.size();
        vector<int> dp(s.size(),-1);
        return helper(0,s,k,dp);
    }
};
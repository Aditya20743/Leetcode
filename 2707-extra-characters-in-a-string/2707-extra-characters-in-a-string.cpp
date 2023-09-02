class Solution {
public:
int helper(int idx,string &s, unordered_set<string>&st,vector<int>&dp){
        
        if(idx>=s.size())return 0;
        
        if(dp[idx]!=-1)return dp[idx];
        
        int ans= 1000;
        
        string str="";
        
        for(int i=0;i+idx<s.size();i++){
            
            str=s.substr(idx,i+1);
            
            if(st.find(str)!=st.end()){
            
                ans=min(ans,helper(idx+i+1,s,st,dp));
            }
            
           ans=min(ans,i+1+ helper(idx+i+1,s,st,dp));
        }
        return dp[idx]= ans;
    }  
    
    int minExtraChar(string s, vector<string>& d) {
        int n=s.size();
        unordered_set<string> st(d.begin(),d.end());
             
        vector<int>dp(n+1,-1);
        
        return helper(0,s,st,dp);
    }
    
    
};

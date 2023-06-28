class Solution {
public:
    int helper(int idx,string s,vector<string>& wordDict,vector<int>&dp ){
        if(idx== s.size())  return 1;
        
        for(int i=0;i<wordDict.size();i++){
            if(wordDict[i][0]== s[idx]){
                int m= wordDict[i].size();
                int j= 0;
                if(dp[idx]!=-1)     return dp[idx];
                while(j<m && wordDict[i][j]==s[idx]){
                    idx++;
                    j++;
                }
                if((j==m) && helper(idx, s, wordDict,dp)==1){
                    return dp[idx]=1;
                }
                idx-=j;
                j=0;
            }
        }
        return dp[idx]=0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n= s.size();
        // unorderd_map<string, int>mp (wordDict.begin(), wordDict.end());
        vector<int> dp(s.size()+1,-1);
        if(helper(0,s, wordDict,dp)==1){
            return true;
        }
        return false;
    }
};


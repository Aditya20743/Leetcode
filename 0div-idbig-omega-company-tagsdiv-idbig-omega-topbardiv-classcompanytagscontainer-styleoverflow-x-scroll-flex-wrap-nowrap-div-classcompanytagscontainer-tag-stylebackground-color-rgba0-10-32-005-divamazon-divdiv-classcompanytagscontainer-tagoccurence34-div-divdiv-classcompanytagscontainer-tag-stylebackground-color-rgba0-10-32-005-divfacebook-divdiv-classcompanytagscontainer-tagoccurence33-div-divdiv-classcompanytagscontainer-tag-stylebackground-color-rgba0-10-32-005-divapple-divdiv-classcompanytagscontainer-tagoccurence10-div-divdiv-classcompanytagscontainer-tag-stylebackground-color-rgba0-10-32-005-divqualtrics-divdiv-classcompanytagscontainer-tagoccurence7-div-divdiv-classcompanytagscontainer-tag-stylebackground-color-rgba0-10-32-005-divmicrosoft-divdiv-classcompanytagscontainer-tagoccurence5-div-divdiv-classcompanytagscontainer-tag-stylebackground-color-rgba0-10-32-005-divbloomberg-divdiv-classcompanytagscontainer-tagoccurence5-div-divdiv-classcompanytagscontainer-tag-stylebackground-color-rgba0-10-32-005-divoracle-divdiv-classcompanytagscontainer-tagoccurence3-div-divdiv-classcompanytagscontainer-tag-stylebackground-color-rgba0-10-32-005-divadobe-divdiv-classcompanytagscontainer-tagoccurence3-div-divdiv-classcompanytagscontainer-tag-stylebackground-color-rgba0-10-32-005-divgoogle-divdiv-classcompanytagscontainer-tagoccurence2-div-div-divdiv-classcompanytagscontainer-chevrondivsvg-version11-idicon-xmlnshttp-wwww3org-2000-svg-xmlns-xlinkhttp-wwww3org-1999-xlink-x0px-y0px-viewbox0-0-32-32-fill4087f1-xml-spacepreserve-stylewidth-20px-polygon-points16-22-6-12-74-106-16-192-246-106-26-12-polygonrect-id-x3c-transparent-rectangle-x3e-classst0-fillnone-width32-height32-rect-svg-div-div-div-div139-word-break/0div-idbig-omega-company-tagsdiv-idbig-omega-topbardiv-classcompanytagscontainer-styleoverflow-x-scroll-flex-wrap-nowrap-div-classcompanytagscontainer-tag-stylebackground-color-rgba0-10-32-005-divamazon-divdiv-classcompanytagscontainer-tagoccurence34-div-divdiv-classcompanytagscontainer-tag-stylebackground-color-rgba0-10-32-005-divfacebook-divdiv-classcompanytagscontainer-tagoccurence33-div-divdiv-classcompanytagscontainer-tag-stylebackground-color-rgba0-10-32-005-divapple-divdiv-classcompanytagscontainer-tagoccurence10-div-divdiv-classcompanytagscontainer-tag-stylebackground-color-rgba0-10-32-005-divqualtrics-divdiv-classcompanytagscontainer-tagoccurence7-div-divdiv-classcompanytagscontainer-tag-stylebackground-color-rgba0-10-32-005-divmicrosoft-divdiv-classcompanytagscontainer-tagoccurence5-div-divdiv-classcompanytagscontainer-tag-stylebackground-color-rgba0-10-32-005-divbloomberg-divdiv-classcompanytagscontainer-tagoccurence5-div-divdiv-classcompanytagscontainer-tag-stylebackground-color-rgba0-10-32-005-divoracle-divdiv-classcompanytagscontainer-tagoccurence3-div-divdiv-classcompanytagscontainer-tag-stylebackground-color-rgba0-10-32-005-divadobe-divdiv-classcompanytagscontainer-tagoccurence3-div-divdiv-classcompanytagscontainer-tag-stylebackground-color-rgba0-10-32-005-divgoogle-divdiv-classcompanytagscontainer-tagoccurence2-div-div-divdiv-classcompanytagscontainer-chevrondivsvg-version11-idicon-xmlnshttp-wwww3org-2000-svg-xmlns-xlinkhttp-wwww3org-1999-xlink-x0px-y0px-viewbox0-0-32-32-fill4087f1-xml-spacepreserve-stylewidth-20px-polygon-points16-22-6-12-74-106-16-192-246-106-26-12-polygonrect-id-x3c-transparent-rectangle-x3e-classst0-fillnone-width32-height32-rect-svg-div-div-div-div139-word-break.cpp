class Solution {
public:
    
    int helper(int i,string s,vector<string>& wordDict, unordered_map<string,int>&mp, vector<int>&memo){
        if(i>=s.size()){
            return 1;
        }
        
        if(memo[i]!= -1){
            return memo[i];
        }
        for(int j=i;j<s.size();j++){
            string temp= s.substr(i,j-i+1);
            if(mp.find(temp)!= mp.end()){
                if(helper(j+1,s,wordDict,mp,memo)== 1){
                    return memo[i]= 1;
                }
            }
        }
        return memo[i]=0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string,int> mp;
        vector<int> memo(s.size()+1,-1);
        
        for(auto it: wordDict){
            mp[it]++;
        }
        
        if(helper(0,s,wordDict,mp,memo)== 1){
            return true;
        }
        return false;
    }
};
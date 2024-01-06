class Solution {
public:
    int helper(int i, vector<int>& startTime, 
               vector<int>& endTime, vector<int>& profit, vector<int>&dp){
        
        if(i==startTime.size()){
            return 0;
        }
        
        if(dp[i]!= -1)      return dp[i];
        
        int take= INT_MIN, not_take=INT_MIN;
        
        
        int ngidx= lower_bound(startTime.begin()+i, startTime.end(), endTime[i]) -
            startTime.begin();
        
        take= helper(ngidx, startTime, endTime, profit,dp) + profit[i];
        
    
        not_take = helper(i+1, startTime, endTime, profit,dp);
        
        return dp[i]= max(take, not_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n= startTime.size();
        
        vector<pair<int,pair<int,int>>> p;
        for(int i=0;i<n;i++){
            p.push_back({startTime[i], {endTime[i], profit[i]}});
        }
        sort(p.begin(), p.end());
        
        
//         vector<int> store;
        
//         for(int i=0;i<n;i++){
//             if(store.empty() || endTime[store.back()])
//         }
        
        vector<int>dp(n+1,-1);
        
        for(int i=0;i<n;i++){
            startTime[i] = p[i].first;
            endTime[i]= p[i].second.first;
            profit[i] = p[i].second.second;
            // cout<<startTime[i]<<" "<<endTime[i]<<endl;
        }
        
        return helper(0, startTime, endTime, profit,dp);
    }
};
class Solution {
public:
//     int helper(int i, string colors, vector<int>&neededTime, vector<int>&dp){
//         if(i==colors.size()){
//             return 0;
//         }
        
//         if(dp[i]!= -1)  return dp[i];
        
//         if(i!=0 && colors[i]== colors[i-1]){
//             int f= helper(i+2, colors, neededTime,dp)+ neededTime[i-1];
//             int s= helper(i+2, colors, neededTime,dp)+ neededTime[i];
            
//             return dp[i]=min(f,s);
//         }
        
//         return dp[i]=helper(i+1, colors, neededTime,dp);
//     }
    
    int minCost(string colors, vector<int>& neededTime) {
        // vector<int> dp(colors.size()+1,-1);
        
        // helper(0,colors, neededTime, dp);
        
        // for(auto it: dp){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        
        //aaabbbabbbb
        
        priority_queue<int, vector<int> , greater<int> > pq;
        int c=0, ans=0;
        for(int i=1;i<colors.size();i++){
            if(colors[i]== colors[i-1] ){
                if(c==0 )
                pq.push(neededTime[i-1]);
                pq.push(neededTime[i]);
                c++;
            }
            else {
                c=0;
                while(pq.size()>1){
                    ans+= pq.top();
                    pq.pop();
                }
                if(pq.size())   pq.pop();   
            }
            // cout<<i<<endl;
        }
        
        while(pq.size()>1){
            ans+= pq.top();
            pq.pop();
        }
        // pq.pop();   
        
        return ans;
    }
};
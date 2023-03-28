class Solution {
public:
    // we have option to buy ticket for only one day/ one week/ one month;
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(days[n-1]+1,0);
        dp[0]=0;
        map<int,int> mp;
        for(auto it: days){
            mp[it]++;
        }
        
        for(int i=1;i<=days[n-1];i++){
            if(mp.count(i)==1){
                int month_ticket= dp[max(i-30,0)]+ costs[2];
                int week_ticket= dp[max(i-7,0)]+ costs[1];
                int day_ticket= dp[max(i-1,0)]+ costs[0];
            
                dp[i]= min(month_ticket,min( week_ticket, day_ticket));
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        return dp[days[n-1]];
    }
};
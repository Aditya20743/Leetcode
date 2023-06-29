//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int helper(int idx,int coins[], int M ,int V, int sum,vector<vector<int>>&dp){
	    if(idx==M){
	        return 1e6;
	    }
	    
	    if(sum== V){
	        return 0;
	    }
	    else if(sum>= V){
	        return 1e6;
	    }
	    
	    if(dp[sum][idx]!= -1)  return dp[sum][idx];
	   
	   
	    
	    int ans= 1e6, take= 1e6,not_take=1e6;
	    
	    take= helper(idx,coins, M ,V, sum+ coins[idx],dp)+1;
	    not_take= helper(idx+1, coins,M ,V, sum, dp);
	    
	    return dp[sum][idx]=min(take,not_take);
	}
	
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int sum=0;
	    vector<vector<int>> dp(V+1,vector<int>(M,-1));
	    return helper(0,coins, M , V, sum,dp)== 1e6 ? -1 : helper(0,coins, M , V, sum,dp);
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
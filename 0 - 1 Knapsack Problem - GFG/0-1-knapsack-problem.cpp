//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int idx, int w, int wt[], int val[], int n,vector<vector<int>>&dp){
        if(idx==n)  return 0;
        
        if(dp[idx][w]!= -1)     return dp[idx][w];
        
        if(wt[idx]>w)   return helper(idx+1, w, wt,val,n,dp);
        
        else{
            int take= helper(idx+1,w-wt[idx],wt,val,n,dp)+ val[idx];
            int not_take= helper(idx+1, w, wt,val,n,dp);
            return dp[idx][w]=max(take,not_take);
        }
        return 0;
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return helper(0,W,wt,val,n,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
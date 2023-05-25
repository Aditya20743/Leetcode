//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int helper(int idx,int curr,vector<int>arr, int sum,vector<vector<int>>&dp){
        
        if(curr> sum){
            return 0;
        }
        if(curr== sum){
            return 1;
        }
        if(idx== arr.size()){
            return 0;
        }
        if(dp[idx][curr]!= -1)return dp[idx][curr];

        return dp[idx][curr]=(helper(idx+1,curr+arr[idx],arr,sum,dp)+
        helper(idx+1,curr,arr,sum,dp));
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>> dp(arr.size(),vector<int>(1e5+1,-1));
        int count=helper(0,0,arr,sum,dp);
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
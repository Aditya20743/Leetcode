class Solution {
public:
    // int mod=1e9+7;
    int helper(int i,int j,vector<int>& nums1, vector<int>&nums2, vector<vector<int>>&dp){
        int n= nums1.size();
        int m= nums2.size();
        
        if(i==n || j==m ){
            return INT_MIN;
        } 
        
        if(dp[i][j]!= -1)   return dp[i][j];
        
        int movei = 0, movej=0, both_take= 0;
        
        both_take=  (nums1[i]*nums2[j]);
        
        movej = helper(i, j+1, nums1, nums2,dp);
        
        movei = helper(i+1, j ,nums1, nums2,dp);
        
        int temp =helper(i+1, j+1, nums1, nums2,dp);
        if(temp >0){
            both_take = (both_take+ temp);
        }
    
        
        return dp[i][j]=max(both_take, max(movei, movej));
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n= nums1.size();
        int m= nums2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(0,0,nums1, nums2 ,dp);
    }
};
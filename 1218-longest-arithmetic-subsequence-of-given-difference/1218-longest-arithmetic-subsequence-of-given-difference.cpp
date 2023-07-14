class Solution {
public:
    // recursion 
//     int helper(int idx,vector<int>& arr, int diff ,int prev){
//         if(idx == arr.size()){
//             return 0;
//         }
        
//         if(prev== -1 ){
//             return max(helper(idx+1, arr, diff, idx) + 1,
//                        helper(idx+1, arr, diff, prev));
//         }
        
//         if(arr[idx]- arr[prev]== diff){
//             return helper(idx+1, arr, diff, idx) + 1;
//         }
//         else {
//             return helper(idx+1, arr, diff, prev);
//         }
        
//     }
    
    int longestSubsequence(vector<int>& arr, int difference) {
        
        // brute force
//         int ans=0;
//         for(int i=0;i<n;i++){
//             int c=1, last= arr[i];
//             for(int j=i+1;j<n;j++){
//                 if(arr[j]- last== difference){
//                     c++;
//                     last= arr[j];
//                 }
//             }
//             ans= max(c, ans);
//         }
        
        
        int n= arr.size();
        unordered_map<int,int> dp;
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(dp.find(arr[i]-difference)!=dp.end()){
                dp[arr[i]]= dp[arr[i]-difference] + 1;
            }
            else{
                dp[arr[i]]=1;
            }
            ans= max(dp[arr[i]],ans);
        }
        
        
        // return helper(0, arr, difference,-1);
        
//         dp[0]=1;
        
//         for(int i=1;i<n;i++){
//             if(arr[i]- )
//         }
        
        return ans;
    }
//      
};
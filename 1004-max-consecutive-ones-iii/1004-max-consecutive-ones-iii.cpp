class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0, ans=0;
        int c=0,n=nums.size();
        
        while(j<n){
            while(j<n && c<=k){
                if(j<n &&nums[j]==0){
                    c++;
                }
                
                if(c>k) break;
                j++;
                ans=max(ans,j-i);
                
            }
            ans=max(ans,j-i);
            
            while(i<=j && c>k){
                if(nums[i]==0){
                    c--;
                }
                i++;
            }
            ans=max(ans,j-i);
            j++;
        }
        
        return ans;
//       [1,1,1,0,0,0,1,0,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,1,0,1,0,1,1,0,1,1,0,1,1,1,0,0,0,1,0,0,0,1,1,1,1,0,0,1]
// 10  
        
        
//         while(j<n && c<k){
//             ans= max(ans,j);
//             if(nums[j]==0){
//                 c++;
//             }
//             j++;
//         }
        
        
//         while(j<n){
//             if(c<=k){
//                 if(nums[j]==0){
//                     c++;
//                     ans= max(ans,j-i);
//                 }
//                 j++;
//             }
//             else{
//                 while(i<j && c>k){
//                     if(nums[i]==0){
//                         c--;
//                     }
//                     i++;
//                 }
//                 if(i==j){
//                     j++;
//                     i++;
//                 }
//                 // ans= max(ans,j-i+1);
//             }
//             j++;
//         }
//         // cout<<endl;
//         return ans;
        
    }
};
class Solution {
public:
    
    int trap(vector<int>& height) {
        
        //optimised
        // two pointer approach
        int n= height.size();
        int left=0,right=n-1, ans=0;
        int lmax=0,rmax=0;
        
        while(left<= right){
            if(height[left]< height[right]){
                if(height[left]>lmax){
                    lmax= height[left];
                }
                else{
                    ans+= lmax- height[left];
                }
                left++;
            }
            else{
                if(height[right]>rmax){
                    rmax= height[right];
                }
                else{
                    ans+= rmax- height[right];
                }
                right--;
            }
        }
        return ans;
        
        
        // brute/ naive approach
//         int n= height.size();
//         vector<int> pre,suf;
//         int maxi=0;
//         for(int i=0;i<n;i++){
//             maxi=max(maxi,height[i]);
//             pre.push_back(maxi);
//         }
//         maxi=0;
//         for(int i=n-1;i>=0;i--){
//             maxi=max(maxi,height[i]);
//             suf.push_back(maxi);
//         }
//         reverse(suf.begin(),suf.end());
//         int ans=0;

//         for(int i=0;i<n;i++){
            
//             ans+= min(suf[i],pre[i])-height[i];
//         }
//         return ans;
        
    }
};
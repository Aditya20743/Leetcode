class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0, j=0;
        int last_idxz=-1;
        int ans=0;
        
        while(j<nums.size()){
            
            if(nums[j]==0){
                i= last_idxz+1;
                last_idxz=j;
            }
            ans= max(ans, j-i);
            j++;
        }
        
        if(ans==nums.size())    ans--;
        return ans;
    }
};
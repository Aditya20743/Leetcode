class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,c=0,ans=0,z=0;
        while(j<nums.size() && i<=j){
            if(nums[j]){
                j++;
                c++;
                ans=max(ans,c+z);
            }
            else{
                z++;
                j++;
                if(z<=k)
                ans=max(ans,c+z);
                else{
                    while(z>k){
                        if(nums[i]==1){
                            c--;
                        }
                        else{
                            z--;
                        }
                        i++;
                    }
                    ans=max(ans,c+z);
                }
                
            }
            
        }
        return ans;
    }
};
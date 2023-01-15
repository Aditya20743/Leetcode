class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int prod=1;
        int z=0;
        int nz=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                prod*=nums[i];
                nz=1;
            }
            
            else{
                z++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(z==1){
                if(nz==0)   ans[i]=0;
                else if(nums[i]==0 && nz==1)  ans[i]=prod;
                
                else    ans[i]=0;
            }
            else if(z>=2){
                ans[i]=0;
            }
            else{
                ans[i]=prod/nums[i];
            }
        }
        return ans;
    }
};
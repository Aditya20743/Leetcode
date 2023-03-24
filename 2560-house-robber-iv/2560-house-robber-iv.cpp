class Solution {
public:
    bool check(int mid,vector<int>&nums, int k){
        int i=0;
        while(i<nums.size() ){
            if(nums[i]< mid){
                k--;
                i+=2;
            }
            else
                i++;
            if(k==0)    return true;
        }
        return k==0;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int ll=1, ul=1e9;
        
        while(ll<= ul){
            int mid= (ll + ul)/2;
            
            if(check(mid,nums,k)){
                ul= mid-1;
            }
            else{
                ll= mid+1;
            }
        }
        return ul;
    }
};
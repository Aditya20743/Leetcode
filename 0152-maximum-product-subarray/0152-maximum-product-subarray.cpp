class Solution {
public:
    void helper(int i, vector<int>&nums, int curr, int& maxi){
        if(i== nums.size()){
            return ;
        }
        maxi =max(maxi, curr);
        
        helper(i+1, nums, 1, maxi);
        
        helper(i+1, nums, curr*nums[i], maxi);
        
    }
    int maxProduct(vector<int>& nums) {
        int maxi= INT_MIN;
        // helper(0, nums, 1, maxi);
        
        int prefix=1, suffix= 1;
        int n= nums.size();
        
        for(int i=0;i<n;i++){
            
            if(prefix==0)   prefix=1;
            if(suffix==0)   suffix=1;
            
            prefix= prefix* nums[i];
            suffix= suffix* nums[n-1-i];
            
            maxi= max(maxi, max(prefix, suffix));
        }
        
        return maxi;
    }
};
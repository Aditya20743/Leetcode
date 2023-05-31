class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=nums[0];
        int curr= 0;
        // if(curr<0)  curr=0;
        
        for(int i=0;i<nums.size();i++){
            curr+= nums[i];
            maxi= max( maxi, curr);
            
            if(curr<0)  curr=0;
        }
        return maxi;
    }
};
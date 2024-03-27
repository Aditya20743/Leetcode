class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int ans=0;
        
        int prod =1;
        
        for(int j=0;j<nums.size();j++){
            prod *= nums[j];
            
            while(prod>=k &&  j>=i){
                prod /= nums[i];
                i++;
            }
            
            ans += j-i+1;
        }
        
        return ans;
    }
};
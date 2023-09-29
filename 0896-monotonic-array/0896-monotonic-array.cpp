class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool f= true;
        
        int n= nums.size();
        
        if(n==1)    return true;
        
        int r = nums[n-1], l= nums[0];
        
        if(l==r){
            for(int i=0;i<n-1;i++){
                if(nums[i]!= nums[i+1])     return false;
            }
        }
        
        else if(l>r){
            for(int i=0;i<n-1;i++){
                if(nums[i]<nums[i+1])     return false;
            }
        }
        
        else if(l<r){
            for(int i=0;i<n-1;i++){
                if(nums[i]>nums[i+1])     return false;
            }
        }
        
        return true;
    }
};
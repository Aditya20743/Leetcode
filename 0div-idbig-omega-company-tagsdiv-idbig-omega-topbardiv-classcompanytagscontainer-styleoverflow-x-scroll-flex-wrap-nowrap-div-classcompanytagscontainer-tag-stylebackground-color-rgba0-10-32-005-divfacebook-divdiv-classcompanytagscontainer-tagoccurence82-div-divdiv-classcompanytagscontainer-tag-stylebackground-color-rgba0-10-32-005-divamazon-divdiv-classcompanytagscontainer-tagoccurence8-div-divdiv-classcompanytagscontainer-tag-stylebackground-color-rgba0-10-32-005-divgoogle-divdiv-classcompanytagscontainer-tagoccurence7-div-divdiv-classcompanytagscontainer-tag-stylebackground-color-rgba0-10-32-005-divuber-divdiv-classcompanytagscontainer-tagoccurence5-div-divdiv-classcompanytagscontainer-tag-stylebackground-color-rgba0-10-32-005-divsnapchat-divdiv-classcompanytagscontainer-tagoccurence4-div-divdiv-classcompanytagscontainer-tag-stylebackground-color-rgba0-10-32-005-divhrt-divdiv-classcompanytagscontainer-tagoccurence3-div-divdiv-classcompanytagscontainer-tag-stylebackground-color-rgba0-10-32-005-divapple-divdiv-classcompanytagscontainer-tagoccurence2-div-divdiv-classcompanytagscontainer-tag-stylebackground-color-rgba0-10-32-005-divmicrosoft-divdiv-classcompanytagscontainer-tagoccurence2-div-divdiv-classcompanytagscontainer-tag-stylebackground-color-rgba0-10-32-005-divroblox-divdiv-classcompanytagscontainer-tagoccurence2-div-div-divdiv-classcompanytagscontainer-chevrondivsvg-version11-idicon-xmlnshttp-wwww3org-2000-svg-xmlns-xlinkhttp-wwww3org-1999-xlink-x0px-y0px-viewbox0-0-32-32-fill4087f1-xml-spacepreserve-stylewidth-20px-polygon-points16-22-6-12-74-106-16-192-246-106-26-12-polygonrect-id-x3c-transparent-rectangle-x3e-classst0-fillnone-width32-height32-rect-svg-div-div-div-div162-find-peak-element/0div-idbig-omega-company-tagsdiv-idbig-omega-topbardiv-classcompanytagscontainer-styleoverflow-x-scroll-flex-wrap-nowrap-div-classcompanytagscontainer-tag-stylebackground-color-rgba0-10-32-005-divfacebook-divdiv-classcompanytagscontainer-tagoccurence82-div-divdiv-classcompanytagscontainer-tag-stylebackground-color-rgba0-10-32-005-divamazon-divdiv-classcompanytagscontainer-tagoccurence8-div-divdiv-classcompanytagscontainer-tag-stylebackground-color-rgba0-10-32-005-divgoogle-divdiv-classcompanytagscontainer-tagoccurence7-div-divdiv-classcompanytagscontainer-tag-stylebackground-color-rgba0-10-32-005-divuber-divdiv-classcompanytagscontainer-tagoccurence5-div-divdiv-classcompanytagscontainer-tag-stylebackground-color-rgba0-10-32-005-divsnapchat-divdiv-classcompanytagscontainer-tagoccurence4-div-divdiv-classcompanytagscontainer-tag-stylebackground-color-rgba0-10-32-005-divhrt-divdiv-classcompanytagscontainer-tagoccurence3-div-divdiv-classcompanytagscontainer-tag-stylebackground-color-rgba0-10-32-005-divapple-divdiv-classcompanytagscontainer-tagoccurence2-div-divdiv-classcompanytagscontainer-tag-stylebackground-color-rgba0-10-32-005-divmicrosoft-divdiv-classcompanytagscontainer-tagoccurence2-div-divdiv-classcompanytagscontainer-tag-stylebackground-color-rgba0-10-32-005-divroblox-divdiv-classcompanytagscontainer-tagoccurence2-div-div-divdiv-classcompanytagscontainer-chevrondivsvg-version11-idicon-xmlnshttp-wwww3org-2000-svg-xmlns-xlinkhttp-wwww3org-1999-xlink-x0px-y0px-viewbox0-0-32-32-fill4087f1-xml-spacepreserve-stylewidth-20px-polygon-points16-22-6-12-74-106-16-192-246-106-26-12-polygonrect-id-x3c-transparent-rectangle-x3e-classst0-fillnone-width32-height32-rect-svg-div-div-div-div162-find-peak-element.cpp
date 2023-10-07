class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        nums.push_back(INT_MIN);
        
        if(n==1)    return 0;
        
        if(nums[0]> nums[1])        return 0;
        
        int l= 0, h= n-1;
        while(l<=h){
            int m= l+(h-l)/2;
            
            if( ( m==0 || nums[m]> nums[m-1] ) && nums[m]>nums[m+1])     return m;
            
            else if(nums[m]< nums[m+1]){
                // increasing 
                // peak on right side
                
                l= m+1;
            }
            else{
                h= m-1;
            }
        }
        
        return -1;
    }
};
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l= 0, r= nums.size()-1;
        if(nums.size()==1)  return 0;
        while(l<=r){
            int m= (l+r)/2;
            if(m== 0 ){
                if(nums[m]> nums[m+1]){
                    return m;}
                else { l= m+1;}
            }
            else if(m== nums.size()-1) {
                if(nums[m] > nums[m-1])  return m;
                else r= m-1;
            }
            else{
                if(nums[m]> nums[m-1] && nums[m]> nums[m+1])    return m;
                else if(nums[m]< nums[m-1]) r= m-1;
                else if(nums[m]> nums[m-1]) l= m+1;
            }
        }
        return -1;
            
    }
};
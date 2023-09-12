class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        
        if(n==1)  return nums[0];
        
        else if(nums[0]!= nums[1])  return nums[0];
        else if(nums[n-1]!= nums[n-2])  return nums[n-1];
        
        int l=1, h=n-2;
        
        while(l<=h){
            int mid = l + (h-l)/2;
            
            if(nums[mid] != nums[mid-1] && nums[mid]!= nums[mid+1])     return nums[mid];
            
            if((mid%2==1 && nums[mid] == nums[mid-1]) || (mid%2==0 && nums[mid] == nums[mid+1])){
                l = mid+1;
                //eliminate the left half:
            } 
            else{
                h = mid-1;
            }
        }
        return -1;
    }
};
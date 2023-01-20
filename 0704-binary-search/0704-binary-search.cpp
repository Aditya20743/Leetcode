class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while( r>=l){
            int m= (l+r)/2;
            if(m>=nums.size())  return -1;
            if( nums[m]>target)  r=m-1;
            else if(nums[m]<target) l=m+1;
            
            else{ return m;}
        }
        return -1;
    }
};
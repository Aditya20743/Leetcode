class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int l=0,h=n-1;
        int mini= nums[0];
        
        while(l<=h){
            int m= l+ (h-l)/2;
            
            // left half sorted
            if(nums[l] <= nums[m]){
                
                mini = min(mini, nums[l]);
                
                l= m+1;
            }
            else{
            // right half sorted
                mini= min(mini, nums[m]);
                h= m-1;
            }
        }
        return mini;
    }
};
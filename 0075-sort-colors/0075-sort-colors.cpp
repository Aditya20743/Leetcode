class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        
        int l=0, r= n-1;
        int m=0;
        while(m<=r){
            // int m= (l+r)/2;
            
            if(nums[m]==2){
                swap(nums[m],nums[r]);
                r--;
            }
            else if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
            else{
                m++;
            }
        }
    }
};
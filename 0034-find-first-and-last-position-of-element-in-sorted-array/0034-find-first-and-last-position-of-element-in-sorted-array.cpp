class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l= 0;
        int r= nums.size()-1;
        while(r>=l){
            int m= l+(r-l)/2;
            if(nums[m]>target){
                r=m-1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
            else {
                int u=m, d=m;
                while(u!=0 && nums[u-1]==target){
                    u--;
                }
                while(d!=nums.size()-1 && nums[d+1]==target){
                    d++;
                }
                return {u,d};
            }
        }
        return {-1,-1};
    }
};
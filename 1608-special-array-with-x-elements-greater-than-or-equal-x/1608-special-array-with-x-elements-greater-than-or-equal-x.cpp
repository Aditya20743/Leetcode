class Solution {
public:
    int solve(vector<int> nums, int tar){
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=tar){
                c++;
            }
        }
        return c;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0; int r= nums.size();
        while(l<=r){
            int mid= (l+r)/2;
            int nos= solve(nums,mid);
            
            if(nos== mid)
                return nos;
            else if(nos> mid){
                l= mid+1;
            }
            else    r= mid-1;
            
        }
        return -1;
    }
};
class Solution {
public:
    bool check(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]> nums[i+1]){
                c++;
            }
        }
        // cout<<c<<endl;
        
        if(nums[n-1]> nums[0]){
            c++;
        }
        
        if(c<=1){
            return true;
        }
        return false;
    }
};
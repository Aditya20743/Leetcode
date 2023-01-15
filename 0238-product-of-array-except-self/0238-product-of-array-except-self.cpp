class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pos(nums.size()+2,1);
        vector<int> pre(nums.size()+2,1);
        vector<int> ans(nums.size());
        
        for(int i=1;i<=nums.size();i++){
            pre[i]=pre[i-1]*nums[i-1];
        }
        for(int i=nums.size()-1;i>=0;i--){
            pos[i]=pos[i+1]*nums[i];
        }
        
        for(int i=0;i<nums.size();i++){
            ans[i]=(pos[i+1]*pre[i]);
        }
        return ans;
    }
};

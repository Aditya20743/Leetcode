class Solution {
public:
    void helper(int idx,vector<vector<int>>&ans,vector<int>&v,vector<int>&nums){
        if(idx == nums.size()){
            return ;
        }
        
        v.push_back(nums[idx]);
        ans.push_back(v);
        helper(idx+1, ans, v, nums);
        
        v.pop_back();
        helper(idx+1, ans, v,nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
        ans.push_back({});
        vector<int> v;
        helper(0, ans, v, nums);        
        return ans;
    }
};
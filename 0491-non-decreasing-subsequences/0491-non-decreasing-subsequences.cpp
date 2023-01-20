class Solution {
public:
    int n;
    void helper(int idx, vector<int>&nums, vector<int>&curr, vector<vector<int>>&res){
        if(curr.size()>=2) res.push_back(curr);
        
        unordered_set<int>st;
        
        for(int i=idx;i<n;i++){
            if((curr.empty() || nums[i]>= curr.back()) && (st.find(nums[i])== st.end())){
                curr.push_back(nums[i]);
                helper(i+1,nums,curr,res);
                curr.pop_back();
                
                st.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        
        vector<vector<int>> res;
        vector<int> curr ;
        
        helper(0,nums,curr,res);
        
        return res;
    }
};
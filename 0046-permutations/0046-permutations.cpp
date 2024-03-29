class Solution {
public:
    void helper( vector<int>&nums, vector<vector<int>>& ans, vector<int>&v,
               unordered_map<int,int>& mp){
        
        if(v.size()== nums.size()){
            ans.push_back(v);
            return;
        }
        
        
        for(int i=0;i<nums.size();i++){
            
            if(mp[nums[i]]== 0){
                
                // helper(i,nums,ans,v,mp);
                
                v.push_back(nums[i]);
                mp[nums[i]]++;
                
                helper(nums, ans, v,mp);
                
                mp[nums[i]]--;
                v.pop_back();
                
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> v;
        unordered_map<int,int> mp;
        
        helper(nums,ans,v,mp);
        
        return ans;
    }
};
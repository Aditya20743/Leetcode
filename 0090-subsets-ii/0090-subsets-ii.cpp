class Solution {
public:
    void helper(vector<int>& temp,vector<int>& nums,set<vector<int>> &s, int idx ){
        if(idx== nums.size()){
            // sort(temp.begin(),temp.end());
            s.insert(temp);
            return ;
        }
        
        temp.push_back(nums[idx]);
        helper(temp, nums, s, idx+1);
        temp.pop_back();
        
        helper(temp, nums, s, idx+1);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        
        vector<vector<int>> ans;
        set <vector<int>> s;
        sort(nums.begin(),nums.end());
        
        helper(temp, nums, s, 0);
        
        for(auto it: s){
            ans.push_back(it);
        }
        
        return ans;
    }
};
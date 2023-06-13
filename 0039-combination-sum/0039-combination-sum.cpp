class Solution {
public:
    void helper(int csum , int idx, vector<int>& candidates, int target, vector<vector<int>>& ans ,vector<int>&v ){
        if( csum == target){
            ans.push_back(v);
            return;
        }
        else if(csum> target){
            return;
        }
        else if(idx>= candidates.size()){
            return;
        }
        helper(csum , idx+1, candidates, target, ans,v);
        
        
        
        v.push_back(candidates[idx]);
        helper(csum+candidates[idx], idx, candidates, target,ans,v);
        v.pop_back();
        

        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        
        helper(0,0, candidates, target,ans,v);
        return ans;
    }
};
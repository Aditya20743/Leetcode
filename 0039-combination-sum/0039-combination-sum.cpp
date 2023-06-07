class Solution {
public:
    void helper(int csum , int idx, vector<int>& candidates, int target, vector<vector<int>>& ans ,vector<int>&v ){
        if( csum == target){
            ans.push_back(v);
        }
        else if(csum> target){
            return;
        }
        else if(idx>= candidates.size()){
            return;
        }
        
        for(int i= idx;i<candidates.size();i++){
            v.push_back(candidates[i]);
            helper(csum+candidates[i], i, candidates, target,ans,v);
            v.pop_back();
        }

        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        
        helper(0,0, candidates, target,ans,v);
        return ans;
    }
};
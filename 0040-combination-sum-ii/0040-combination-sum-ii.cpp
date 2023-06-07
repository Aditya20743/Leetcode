class Solution {
public:
    void helper(int idx, int curr_sum, vector<int>& candidates, int target, 
                vector<int>& curr_vector,vector<vector<int>>& ans){
        
        if(curr_sum == target){
            ans.push_back(curr_vector);
            return;
        }
        else if( curr_sum> target){
            return;
        }
        else if( idx >= candidates.size()){
            return;
        }
        
        
        // while(idx>0 && candidates[idx]== candidates[idx-1]){
        //     idx++;
        // }
        // if(idx>0 && candidates[idx-1]==candidates[idx-2])   idx--;
        
        curr_vector.push_back(candidates[idx]);
        helper(idx+1, curr_sum+ candidates[idx], candidates, target, curr_vector, ans);
        curr_vector.pop_back();
        
        int x=-1;
        if(idx<candidates.size())
            x= candidates[idx];
        
        while(idx<candidates.size() && candidates[idx] == x ) {
            idx++;
            // cout<<idx<<endl;
        }

        helper(idx, curr_sum, candidates, target, curr_vector, ans);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        
        // vector<vector<int>> res;
        
        vector<int> curr_vector;
        
        helper(0, 0, candidates, target, curr_vector, ans);
        
        // for(auto it: ans){
        //     res.push_back(it);
        // }
        
        return ans;
    }
};
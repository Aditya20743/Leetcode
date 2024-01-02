class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=0;
        for(auto it: nums){
            mp[it]++;
            maxi=max(mp[it], maxi);
            
        }
        vector<vector<int>> ans(maxi);
        vector<int> v;
        sort(nums.begin(),nums.end());
        
        vector<int> level(nums.size());
        level[0]=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                level[i]= level[i-1]+1;
            }
            else{
                level[i]=1;
            }
        }
        
        // for(auto it: level) cout<<it<<" ";
        // cout<<endl;
        
        for(int i=0;i<nums.size();i++){
            ans[level[i]-1].push_back(nums[i]);
        }
        return ans;
//         unordered_map<int,int>mp;
//         int maxi=0;
//         for(auto it: nums){
//             mp[it]++;
//             maxi=max(mp[it], maxi);
//             if(mp[it]==1){
//                 v.push_back(it);
//             }
//         }
//         ans.push_back(v);
//         for(auto it: v){
//             mp[it]--;
//         }
//         v.clear();
        
//         for(int i=2;i<= maxi;i++){
//             for(auto it: nums){
//                 mp[it]++;
//                 if(mp[it]==1){
//                     v.push_back(it);
//                 }
//             }
//             if(v.size()>0)
//             ans.push_back(v);
//             v.clear();
//         }
//         return ans;
    }
};
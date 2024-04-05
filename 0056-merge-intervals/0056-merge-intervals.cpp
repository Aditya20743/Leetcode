class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;
        sort(v.begin(), v.end());
        
        int st= v[0][0];
        int end = v[0][1];
        
        for(int i=1;i<v.size();i++){
            if(end >= v[i][0]){
                end = max(end, v[i][1]);
            }
            else{
                ans.push_back({st,end});
                st= v[i][0];
                end = v[i][1];
            }
        }
        ans.push_back({st,end});
        
        return ans;
    }
};
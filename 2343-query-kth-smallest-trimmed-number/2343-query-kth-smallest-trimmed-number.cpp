class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& a, vector<vector<int>>& q) {
        vector<int> ans;
        
        for(auto it: q){
            
            vector<pair<string,int>> v;
            for(int i=0;i<a.size();i++){
                string s="";
    
                for(int j=a[i].size()-it[1];j<a[i].size();j++){
                    s+=a[i][j];
                }
                // cout<<nm<<" ";
                v.push_back({s, i});
            }
            // cout<<endl;
            
            sort(v.begin(),v.end());
            
            // cout<<it[0]-1<<" ";
            ans.push_back(v[it[0]-1].second);
        }
        
        return ans;
    }
};
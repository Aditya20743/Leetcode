class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& a) {
        vector<string> ans;
        
        map<string,vector<string>> mp;
        
        if(a.size()<3)  return ans;
        
        for(auto it: a){
            mp[it[0]].push_back(it[1]);
        }
        
        for(auto it: mp){
            vector<string> t= it.second;
            sort(t.begin(),t.end());
            // cout<<t.size()<<" ";
            if(t.size()<3)  continue;
            for(int i=0;i<t.size()-2;i++){
                // cout<<stoi(t[i+2])<<" ";
                if(stoi(t[i+2])- stoi(t[i]) <100){
                    ans.push_back(it.first);
                    break;
                }
            }
        }
        
        return ans;
    }
};
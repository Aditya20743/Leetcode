class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<double,int>> v(spells.size());
        for(int i=0;i<spells.size();i++){
            v[i]=  {(1.0*success)/(spells[i]*1.0),i};
            
            // cout<<v[i]<<endl;
        }
        sort(v.begin(),v.end());
        sort(potions.begin(),potions.end());
        
        vector<pair<int,int>> res(spells.size());
        
        for(int i=0;i<spells.size();i++){
            int idx =lower_bound(potions.begin(), potions.end(), v[i].first)-potions.begin();
            // cout<<idx<<endl;
            res[i]={v[i].second,(potions.size()-idx)};
        }
        sort(res.begin(),res.end());
        
        vector<int> ans;
        for(int i=0;i<res.size();i++){
            ans.push_back(res[i].second);
        }
        
        return ans;
        
    }
};
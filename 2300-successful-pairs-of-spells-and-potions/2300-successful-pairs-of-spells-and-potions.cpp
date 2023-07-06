class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<pair<double,int>> v(spells.size());
        for(int i=0;i<spells.size();i++){
            v[i]=  {(1.0*success)/(spells[i]),i};
        }
        sort(potions.begin(),potions.end());
        
        vector<pair<int,int>> res(spells.size());
        
        vector<int> ans;
        
        for(int i=0;i<spells.size();i++){
            
            int idx =lower_bound(potions.begin(), potions.end(), v[i].first)-potions.begin();
            ans.push_back(potions.size()-idx);
        }
    
        
        return ans;
        
    }
};
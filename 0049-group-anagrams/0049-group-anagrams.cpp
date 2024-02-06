class Solution {
    // map -> sorted string -> kiti same strings ahe.
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string ,vector<string>> mp;
        
        for(auto it: strs){
            string t = it;
            sort(t.begin(),t.end());
            mp[t].push_back(it);
        }
        vector<vector<string>> ans;
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
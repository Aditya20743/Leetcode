class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<int,int> mp;
        for(auto it: words){
            for(auto x: it)
            mp[x-'a']++;
        }
        
        for(auto it: mp){
            if(it.second% words.size()!=0){
                return false;
            }
        }
        return true;
    }
};
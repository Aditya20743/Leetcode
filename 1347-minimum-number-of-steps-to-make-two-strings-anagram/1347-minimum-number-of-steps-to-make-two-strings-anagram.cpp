class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int> mp;
        for(auto it: s){
            mp[it-'a']++;
        }
        
        for(auto it: t){
            mp[it-'a']--;
        }
        
        int c=0;
        for(auto it: mp){
            if(it.second>0){
                c+= it.second;
            }
        }
        
        return c;
    }
};
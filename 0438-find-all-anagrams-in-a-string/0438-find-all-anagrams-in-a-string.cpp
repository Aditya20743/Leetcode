class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mp,mp2;
        for(auto it: p) mp2[it]++;
        int z= p.size();
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            if(i >= z-1){
                if(mp== mp2)   ans.push_back(i-z+1); 
                mp[s[i-z+1]]--;
                if(mp[s[i-z+1]]==0) mp.erase(s[i-z+1]);
            }
        }
        return ans;
    }
};
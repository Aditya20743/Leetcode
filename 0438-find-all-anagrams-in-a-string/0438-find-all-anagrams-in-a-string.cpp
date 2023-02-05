class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>mp(26,0),mp2(26,0);
        for(auto it: p) mp2[it-'a']++;
        int z= p.size();
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
            if(i >= z-1){
                // for(auto it: mp)
                // cout<<it<<" ";
                // cout<<endl;
                if(mp== mp2)   ans.push_back(i-z+1); 
                mp[s[i-z+1]-'a']--;
                //if(mp[s[i-z+1]]==0) mp.erase(s[i-z+1]);
            }
        }
        // cout<<endl;
        
        return ans;
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26,0), mp2(26,0);
        for(auto it: s1){
            mp1[it-'a']++;
        }
        if(s1.size()>s2.size()) return false;
        for(int i=0;i<s2.size();i++){
            
            if(i >= s1.size())    mp2[s2[i-s1.size()]-'a']--;
            mp2[s2[i]-'a']++;
            if(mp1==mp2)    return true;
        }
        return false;
    }
};
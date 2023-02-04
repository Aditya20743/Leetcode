class Solution {
public:
    bool check(string x,string s){
        unordered_map<char,int> mp1,mp2;
        for(auto it: x) mp1[it]++;
        for(auto it: s) mp2[it]++;
        return mp1==mp2;
    }
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        int z= s1.size();
        if(z>s2.size()) return false;
        for(auto it: s1)    mp[it]++;
        
        for(int i=0;i<s2.size()-z+1;i++){
            if(mp[s2[i]]>0){
                string x= s2.substr(i,z);
                if(check(x,s1)) return true;
            }
        }
        return false;
    }
};
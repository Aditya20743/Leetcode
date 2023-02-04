class Solution {
public:
    bool check(string x,string s){
        //unordered_map<char,int> mp1,mp2;
        vector<int> b(26),c(26);
        for(int i=0;i<26;i++){b[i]=0; c[i]=0; }   
        for(char it: x) b[it-'a']++;
        for(char it: s) c[it-'a']++;
        return b==c;
    }
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        int a[26];
        for(int i=0;i<26;i++)   a[i]=0;
        
        int z= s1.size();
        if(z>s2.size()) return false;
        for(char it: s1)    a[it-'a']++;
        
        for(int i=0;i<s2.size()-z+1;i++){
            if(a[s2[i]-'a']>0){
                string x= s2.substr(i,z);
                if(check(x,s1)) return true;
            }
        }
        return false;
    }
};
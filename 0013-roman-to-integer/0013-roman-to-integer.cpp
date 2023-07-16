class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        if(s.size()==1){
            return mp[s[0]];
        }
        
        int ans=0;
        for(int i=0;i<s.size()-2;i++){
            if(mp[s[i]]>=mp[s[i+1]]){
                ans+= mp[s[i]];
            }
            else{
                ans+= -mp[s[i]];
                // i++;
            }
        }
        if(s.size()>=2){
            if(mp[s[s.size()-2]]>= mp[s[s.size()-1]]){
                ans+= mp[s[s.size()-2]] + mp[s[s.size()-1]];
            }
            else{
                ans+= -mp[s[s.size()-2]] + mp[s[s.size()-1]];
            }
        }
        
        return ans;
    }
};
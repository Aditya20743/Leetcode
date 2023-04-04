class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mp;
        int c=1;
        for(int i=0;i<s.size();){
            mp[s[i]]++;
            if(mp[s[i]]==2){
                c++;
                mp.clear();
            }else{
                i++;
            }
        }
        return c;
    }
};
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> mp1,mp2;
        if(word1.size()!=word2.size())   return false;
        for(int i=0;i<word1.size();i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
        vector<int> v1,v2;
        vector<char> c1,c2;
        for(auto it: mp1){
            c1.push_back(it.first);
            v1.push_back(it.second);
        }
        for(auto it: mp2){
            c2.push_back(it.first);
            v2.push_back(it.second);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(c1.begin(),c1.end());
        sort(c2.begin(),c2.end());
        
        return v1==v2 && c1==c2;
    }
};
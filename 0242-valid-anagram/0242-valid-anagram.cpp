class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq (26,0);
        
        if(s.size()!= t.size())     return false;
        
        // rat , cat r=1, a=1, t=1,  =>  c==0 => false;
        
        for(auto it: s){
            freq[it-'a']++;
        }
        for(auto it: t){
            
            if(freq[it-'a']==0){
                return false;
            }
            freq[it-'a']--;
        
        }
        
        return true;
    }
};
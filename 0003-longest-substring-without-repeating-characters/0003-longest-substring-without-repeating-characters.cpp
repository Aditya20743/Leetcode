class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1) return 1;
        int l=0;
        int r=0;
        int maxi=0;
        map<char,int> mp;
        
        while(r<s.size()){
            mp[s[r]]++;
            if(mp[s[r]]==2){
                while(mp[s[r]]!=1){
                    mp[s[l++]]--;
                    // s[i++]==s[r];
                }
               
            }
             maxi=max(r-l+1,maxi);
            r++;
        }
        maxi=max(r-l,maxi);
        return maxi;
        
//         for(int i=0;i<s.size();i++){
//             if(mp[s[i]]<2){
//                 r++;
//                 mp[s[i]]++;
//             }
//             else{
                
//             }
//         }
    }
};
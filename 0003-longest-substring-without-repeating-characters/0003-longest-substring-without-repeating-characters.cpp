class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        map<char,int> mp;
        int ans=0;
        while(r< s.size()){
            if(mp[s[r]]==0){
                mp[s[r]]++;
                r++;
                ans=max(ans,r-l);
            }
            
            else{
                while(mp[s[r]]!=0){
                    mp[s[l]]--;
                    l++;
                }
            }
        }
        return ans;
    }
};
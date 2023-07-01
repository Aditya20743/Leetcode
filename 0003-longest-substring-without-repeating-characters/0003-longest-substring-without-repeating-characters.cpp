class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i=0,j=0, n= s.size();
        int ans= 0;
        while(i<n){
            if(mp[s[i]]==1){
                while(mp[s[i]]!=0){
                    mp[s[j]]--;
                    j++;
                }
                // ans= max(ans, i-j);
                
            }
            else{
                mp[s[i]]++;
                i++;
                ans= max(ans, i-j);
            }
            // i++;
        }
        // ans= max(ans, i-j+1);
        
        
        return ans;
    }
};
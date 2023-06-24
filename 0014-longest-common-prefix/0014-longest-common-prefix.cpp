class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        
        int n= min(strs[0].size(), strs[strs.size()-1].size());
        
        string ans="";
        for(int i=0;i<n;i++){
            if(strs[0][i]== strs[strs.size()-1][i]){
                ans+= strs[0][i];
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};
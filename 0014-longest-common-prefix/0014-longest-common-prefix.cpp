class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans= strs[0];
        
        for(int i=1;i<strs.size();i++){
            for(int j=0;j<ans.size();j++){
                if(strs[i][j]!= ans[j]){
                    ans.erase(ans.begin()+j,ans.end());
                    continue;
                }
            }
        }
        return ans;
    }
};
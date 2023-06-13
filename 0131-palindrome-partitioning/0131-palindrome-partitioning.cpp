class Solution {
public:
    void helper(int i,vector<string>&path, string s, vector<vector<string>>& ans){
        int n= s.size();
        if(i==n){
            ans.push_back(path);
            return;
        }
        
        for( int j=i;j<n;j++){
            string t= s.substr(i, j-i+1);
            string x= t;
            reverse(x.begin(),x.end());
            if(x==t ){
                path.push_back(x);
                
                helper(j+1,path, s, ans);
                path.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        helper(0,path, s, ans);
        
        return ans;
    }
};
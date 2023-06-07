class Solution {
public:
    void helper(int n, vector<string>& ans, string s,int open){
        
        if(n==0) {
            int x=open;
            while(x--)
                s+= ')';
            ans.push_back(s);
            return;
        }
        s+= '(';
        helper(n-1, ans, s, open+1);
        
        
        if(open>0){
            s.pop_back();
            s+= ')';
            helper(n, ans, s, open-1);
        }
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string s="";
        helper(n,ans,s,0);
        
        return ans;
    }
};
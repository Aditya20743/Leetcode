class Solution {
public:
    void helper(int idx,vector<int>& cookies, vector<int>&kids, int&ans ){
        
        if(idx== cookies.size()){
            int m= *max_element(kids.begin(),kids.end());
            ans= min(ans, m);
            return ;
        }
        
        for(int i=0;i<kids.size();i++){
            kids[i]+= cookies[idx];
            
            helper(idx+1, cookies, kids, ans);
            
            kids[i]-= cookies[idx];
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        
        vector<int> kids(k);
        
        int ans=INT_MAX;
        
        helper(0, cookies, kids, ans);
        
        return ans;
    }
};
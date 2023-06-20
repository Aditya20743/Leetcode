class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        
        vector<string> v;
        string t="";
        bool f=false;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(f){
                    v.push_back(t);
                    t="";
                }
                f=false;
            }
            else{
                t+= s[i];
                f=true;
            }
        }
        if(f){
            v.push_back(t);
        }
        
        for(int i=v.size()-1;i>=0;i--){
            ans+= v[i];
            ans+= " ";
        }
        ans.pop_back();
        
        return ans;
    }
};
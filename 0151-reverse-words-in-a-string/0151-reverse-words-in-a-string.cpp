class Solution {
public:
    string reverseWords(string s) {
        string ans= "";
        int i=0;
        while(s[i]==' '){
            i++;
        }
        string w;
        while(i<s.size()){
            while(i<s.size() && s[i]!=' '){
                ans+= s[i];
                i++;
            }
            while(i<s.size() && s[i]==' '){
                i++;
            }
            w = ans +" "+ w;
            ans="";
        }
        if(ans.size() > 0){
            w = ans +" "+ w;
        }
        i = w.size()-1;
        while(w[i]==' '){
            w.pop_back();
        }
        return w;
    }
};
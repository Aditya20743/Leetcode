class Solution {
public:
    string makeGood(string s) {
        bool f= true;
        int i=0;
        while(f){
            f=false;
            for(int i=0;i<s.size();i++){
                if(i!= s.size() && (s[i]==s[i+1]+'a'-'A' || s[i+1]==s[i]+'a'-'A')){
                    s.erase(s.begin()+i, s.begin()+i+2);
                    f=true;
                    break;
                }
            }
        }
        return s;
    }
};
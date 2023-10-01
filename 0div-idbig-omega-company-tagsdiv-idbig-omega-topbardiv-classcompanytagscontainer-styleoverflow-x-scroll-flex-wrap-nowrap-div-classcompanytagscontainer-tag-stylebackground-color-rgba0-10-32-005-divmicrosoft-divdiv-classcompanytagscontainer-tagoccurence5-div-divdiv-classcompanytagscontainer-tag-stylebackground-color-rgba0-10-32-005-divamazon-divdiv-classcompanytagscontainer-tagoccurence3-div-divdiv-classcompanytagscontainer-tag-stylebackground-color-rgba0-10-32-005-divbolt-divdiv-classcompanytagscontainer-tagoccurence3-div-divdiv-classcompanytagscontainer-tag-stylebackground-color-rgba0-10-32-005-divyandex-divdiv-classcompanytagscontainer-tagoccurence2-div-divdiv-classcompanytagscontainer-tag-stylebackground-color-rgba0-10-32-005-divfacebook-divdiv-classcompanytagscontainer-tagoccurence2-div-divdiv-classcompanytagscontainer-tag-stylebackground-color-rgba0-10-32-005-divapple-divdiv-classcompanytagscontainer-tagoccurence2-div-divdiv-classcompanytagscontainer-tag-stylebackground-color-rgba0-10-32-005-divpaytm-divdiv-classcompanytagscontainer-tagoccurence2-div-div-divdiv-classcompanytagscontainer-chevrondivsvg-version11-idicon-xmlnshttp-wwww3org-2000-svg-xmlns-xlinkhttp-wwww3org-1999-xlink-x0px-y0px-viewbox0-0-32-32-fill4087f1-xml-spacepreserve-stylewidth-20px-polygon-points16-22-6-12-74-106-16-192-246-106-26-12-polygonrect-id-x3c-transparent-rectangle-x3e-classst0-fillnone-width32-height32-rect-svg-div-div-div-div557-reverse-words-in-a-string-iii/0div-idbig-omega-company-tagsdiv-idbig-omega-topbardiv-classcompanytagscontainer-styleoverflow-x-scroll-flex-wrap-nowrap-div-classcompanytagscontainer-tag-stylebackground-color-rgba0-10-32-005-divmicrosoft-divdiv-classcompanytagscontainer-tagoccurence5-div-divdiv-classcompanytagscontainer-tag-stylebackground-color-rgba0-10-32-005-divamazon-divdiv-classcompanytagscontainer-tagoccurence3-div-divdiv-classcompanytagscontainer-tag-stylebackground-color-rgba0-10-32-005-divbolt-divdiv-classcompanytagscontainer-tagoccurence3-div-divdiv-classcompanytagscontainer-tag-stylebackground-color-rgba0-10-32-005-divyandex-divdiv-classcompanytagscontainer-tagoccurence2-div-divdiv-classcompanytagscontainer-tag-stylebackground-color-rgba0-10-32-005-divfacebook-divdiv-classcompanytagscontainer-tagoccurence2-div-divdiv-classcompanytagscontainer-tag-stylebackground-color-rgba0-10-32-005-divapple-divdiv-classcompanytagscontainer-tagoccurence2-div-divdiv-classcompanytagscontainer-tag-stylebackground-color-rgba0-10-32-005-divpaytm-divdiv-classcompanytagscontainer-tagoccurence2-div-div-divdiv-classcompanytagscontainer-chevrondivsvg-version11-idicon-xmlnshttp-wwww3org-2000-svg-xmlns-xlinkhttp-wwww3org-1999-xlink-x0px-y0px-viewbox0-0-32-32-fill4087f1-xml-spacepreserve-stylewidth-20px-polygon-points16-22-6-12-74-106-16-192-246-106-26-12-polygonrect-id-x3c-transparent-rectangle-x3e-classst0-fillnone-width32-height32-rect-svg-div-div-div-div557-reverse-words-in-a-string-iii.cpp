class Solution {
public:
    string reverseWords(string s) {
        int l=0,n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]==' ' && i>0){
                reverse(s.begin()+l,s.begin()+i);
                l=i+1;
            }
        }
        reverse(s.begin()+l,s.end());
        
        return s;
    }
};
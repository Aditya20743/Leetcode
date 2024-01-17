class Solution {
public:
    int minSwaps(string s) {
        int o=0,z=0;
        string s1="",s2="";
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')   o++;
            else    z++;
            if(i%2==0 ){
                s1+= '1';
                s2+='0';
            }
            else{
                s2+= '1';
                s1+='0';
            }
        }
        
        if(abs(o-z)>=2)     return -1;
        
        int c=0;
        int c2=0;
        if(o>z){
            
            for(int i=0;i<s.size();i++){
                if(s[i]!=s1[i]){
                    c++;
                }
            }
            return c/2;
        }
        else if(z>o){
            c=0;
            for(int i=0;i<s.size();i++){
                if(s[i]!=s2[i]){
                    c++;
                }
            }
            return c/2;
        }
        
        else {
            
            for(int i=0;i<s.size();i++){
                if(s[i]!=s1[i]){
                    c++;
                }
                if(s[i]!=s2[i]){
                    c2++;
                }
            }
        }
        cout<<s1<<" "<<s2<<endl;
        return min(c/2,c2/2);
    }
};
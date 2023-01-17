class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int z=0,o=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'){
                j=i;
                break;
            }
        }
        for(int i=j;i<s.size();i++){
            if(s[i]=='0'){
                z++;
            }
            else if(s[i]== '1'){
                o++;
            }
            if(z>o){
                z=o;
            }
            // else if(z<o){
            //     swap(z,o);
            // }
        }
        return min(o,z);
    }
};
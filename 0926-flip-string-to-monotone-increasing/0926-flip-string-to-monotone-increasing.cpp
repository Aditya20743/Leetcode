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
        // Don't worry about 0s before 1 as they are at their right place.
        // FIND index where 1st ONE occurs and store it in j;
        // keep count of zeros and ones in z and o respectively
        
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
        }
        return min(o,z);
        
// 00110 ->reduced to 110-> change last 0 to 1 rather than two 1's to 0.
// 1100011 -> till 4th index, z=3,o=2 now we will swap the values, 
// to preserve the count of o.
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size()-1;
        int count=0;
        while(s[n]==' '){
            n--;
        }
        for(int i=n;i>=0;i--){
            if(s[i]!= ' '){
                count++;
            }
            else{
                break;
            }
        }
        
        return count;
    }
};
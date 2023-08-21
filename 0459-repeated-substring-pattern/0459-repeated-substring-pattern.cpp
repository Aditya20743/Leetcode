class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n= s.size();
        
        for(int i=1;i<=n/2;i++){
            
            if(n%i ==0){
                
                int times= n/i;
                string temp= s.substr(0,i);
                string check = "";
                while(times--){
                    check+= temp;
                }
                
                if(check==s){
                    return true;
                } 
            }
        }
        
        return false;
    }
};
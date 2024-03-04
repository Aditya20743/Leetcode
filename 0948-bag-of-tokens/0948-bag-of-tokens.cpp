class Solution {
public:    
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        
        int i=0,r=tokens.size()-1;
        int sc=0;
        int res=0;
        
        while(i<=r){
            if(power>= tokens[i]){
                power-= tokens[i];
                sc++;
                i++;
                res= max(res, sc);
            }
            else if(sc>0 && power< tokens[r]){
                power+= tokens[r];
                r--;
                sc--;
            }
            else{
                break;
            }
        }
        return res;
    }
};
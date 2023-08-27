class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lc=0, rc=0, d=0;
        for(auto it: moves){
            if(it=='L')lc++;
            else if(it=='R')rc++;
            else    d++;
        }
        
        return d+ abs(lc-rc);
    }
};
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int charCol =( coordinate1[0]-'a')%2;
        // charCol =0 => black else white
        int noCol = (coordinate1[1]-'1')%2;
        if(noCol == 1){
            charCol = (charCol +1)%2;
        }
        
        int charCol2 =( coordinate2[0]-'a')%2;
        // charCol =0 => black else white
        int noCol2 = (coordinate2[1]-'1')%2;
        if(noCol2 == 1){
            charCol2 = (charCol2 +1)%2;
        }
        
        if(charCol == charCol2){
            return true;
        }
        return false;
    }
};
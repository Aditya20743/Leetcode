class Solution {
public:
    bool isPowerOfTwo(int n) {
        int c=0;
        if(n<0) return false;
        for(int i =0;i<32;i++){
            int bit= (n & 1<<i);
            if(bit){
                c++;
            }
        }
        if(c==1)    return true;
        return false;
    }
};
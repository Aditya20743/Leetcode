class Solution {
public:
    int countOdds(int low, int high) {
        if(high%2==0)   high--;
        if(low%2==0)    low++;
        int diff= (high- low)/2;
        return diff+1;
        // int c=0;
        // for(int i=low;i<=high;i++){
        //     if(i%2==1){
        //         c++;
        //     }
        // }
        // return c;
        // 0 7 -4   1 7 -4   1 8 -4    4  8  2  
    }
};
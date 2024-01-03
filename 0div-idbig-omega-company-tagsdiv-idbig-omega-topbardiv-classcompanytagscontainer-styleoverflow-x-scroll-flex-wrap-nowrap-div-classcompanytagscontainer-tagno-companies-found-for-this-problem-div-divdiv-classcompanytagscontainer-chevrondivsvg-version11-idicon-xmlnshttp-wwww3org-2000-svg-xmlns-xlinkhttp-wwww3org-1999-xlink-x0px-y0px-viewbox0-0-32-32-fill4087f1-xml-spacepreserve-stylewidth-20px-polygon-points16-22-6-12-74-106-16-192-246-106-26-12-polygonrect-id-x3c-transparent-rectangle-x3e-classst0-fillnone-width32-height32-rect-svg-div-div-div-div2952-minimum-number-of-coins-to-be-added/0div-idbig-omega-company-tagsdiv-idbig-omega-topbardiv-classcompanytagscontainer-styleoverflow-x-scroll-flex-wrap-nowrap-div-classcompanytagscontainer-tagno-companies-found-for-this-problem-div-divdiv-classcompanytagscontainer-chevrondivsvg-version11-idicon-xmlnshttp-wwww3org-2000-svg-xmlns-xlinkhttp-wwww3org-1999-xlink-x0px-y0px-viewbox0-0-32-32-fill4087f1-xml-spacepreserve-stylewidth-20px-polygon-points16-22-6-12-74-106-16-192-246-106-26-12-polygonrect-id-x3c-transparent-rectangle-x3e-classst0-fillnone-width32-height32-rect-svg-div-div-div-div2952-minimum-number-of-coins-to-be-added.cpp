class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int i=0,add=0,limit=0;
        sort(coins.begin(), coins.end());
        
        while(limit<target){
            
            if( (i<coins.size() && limit+1< coins[i])|| i>=coins.size()){
                add++;
                limit+= limit+1;
            }
            else {
                limit+= coins[i];
                i++;
            }
        
        }
        
        return add;
    }
};
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        
        int n= piles.size();
        int i= n-2;
        int c=0;
        int ans=0;
        while(c!= n/3 ){
            ans+= piles[i];
            c++;
            i= i-2;
        }
        return ans;
    }
};
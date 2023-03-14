class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=prices[0];
        int mini=prices[0], profit=0;
        for(auto it: prices){
            //maxi= max(it,maxi);
            mini= min(it,mini);
            profit= max(it-mini,profit);
        }
        return profit;
    }
};
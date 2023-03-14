class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, mini= prices[0];
        for(int i=0;i<prices.size();i++){
            if(mini< prices[i]){
                ans+= prices[i]-mini;
                mini= prices[i];
            }
            else
                mini=prices[i];
            
        }
        return ans;
    }
};
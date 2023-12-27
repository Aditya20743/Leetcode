class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mini=0;
        
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                mini += min(neededTime[i-1], neededTime[i]);
                neededTime[i] = max(neededTime[i-1], neededTime[i]);
            }
    
        }
        
        return mini;
    }
};
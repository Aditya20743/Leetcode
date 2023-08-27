class Solution {
public:
    int helper(int i, vector<int> &stones, int last_idx, vector<vector<int>> &dp){
        if(i== stones.size() -1){
            return true;
        }
        
        // int j = i+1;
        
        if(dp[i][last_idx]!= -1)    return dp[i][last_idx];
        
        int f= 0;
        
        int last_jump= stones[i] - stones[last_idx];
        
        for(int j= i+1;j<stones.size();j++){
            
            if((stones[j] - stones[i] == last_jump+1 ||
              stones[j]- stones[i] == last_jump ||
             stones[j] - stones[i] == last_jump-1)){
                
                f= helper(j,stones, i,dp);
                if(f)   return dp[j][i] = 1;
                
            }
            else if(stones[j] - stones[i] > last_jump+1)    break;
        }
        
        return dp[i][last_idx]=f;
        
//         while( (stones[j] - stones[i] == last_jump+1 ||
//               stones[j]- stones[i] == last_jump ||
//              stones[j] - stones[i] == last_jump-1)){
            
//             f= helper(j, stones, stones[j] - stones[i]);
    
//             if(f==true) return true;
//             cout<<stones[j] - stones[i]<<" "<<j<<" - "<<i<<endl;

//             j++;
//         }
        // cout<<last_jump<<" "<<j-1<<" - "<<i<<endl;
        // return false;
        
    }
    
    bool canCross(vector<int>& stones) {
        int n= stones.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return helper(0 , stones , 0,dp);
    }
};
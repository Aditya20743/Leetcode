class Solution {
public:
    int MOD = 1e9 + 7;
 
//     long long helper(int i, int k, vector<int> nums, vector<vector<long long>> &dp){
//         if(i== nums.size() || k==0){
//             return prod(nums);
//         }
        
//         if(dp[i][k]!= -1)   return dp[i][k];
//         nums[i]+= 1;
//         long long take= helper(i, k-1, nums, dp)%MOD;
    
//         nums[i]-=1;
//         long long not_take= helper(i+1 ,k ,nums, dp)%MOD;
        
//         return dp[i][k]= max(take, not_take);
        
        
//     }
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(auto it: nums){
            pq.push(it);
        }
        
        while(k--){
            int t= pq.top();
            pq.pop();
            pq.push(t+1);
        }
        long long ans=1;
        while(!pq.empty()){
            int t= pq.top();
            pq.pop();
            ans =(ans*t)%MOD;
            cout<<ans<<" ";
            
        }
        cout<<endl;
        return (int)ans;
    }
};
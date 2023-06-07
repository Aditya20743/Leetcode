class Solution {
public:
//     int helper(int idx,vector<int>& chargeTimes, vector<int>& runningCosts, long long budget ){

//         long long maxCT=0, sumRT=0;
//         int n= chargeTimes.size();
//         long long cost=0;
//         int ans=0;
//         for(int i=idx;i<n;i++){
//             maxCT= max(maxCT,1LL*chargeTimes[i] );
//             sumRT= sumRT+ 1LL*runningCosts[i];
            
//             cost= maxCT + (i- idx+1)* sumRT;
//             if(cost> budget){
//                 break;
//             }
//             else{
//                 ans= i-idx+1;
//             }
//         }
//         return ans;
//     }
    
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n= chargeTimes.size();
        int ans=0;
        long long maxCT=0, sumRT=0;
        long long cost=0;
        priority_queue<pair<int,int>> pq;
        int j=0;
        
        for(int i=0;i<n;i++){
    
            sumRT= sumRT+ 1LL*runningCosts[i];
            pq.push({chargeTimes[i],i});
            
            while(!pq.empty() && pq.top().second< j)    pq.pop();
            
            if(pq.empty())  cost=0;
            else
                cost= pq.top().first + (i- j+1)* sumRT;
            
            while(cost> budget){
                sumRT= sumRT- runningCosts[j++];
                while(!pq.empty() && pq.top().second< j)    pq.pop();
            
                if(pq.empty())  cost=0;
                else
                cost= pq.top().first + (i- j+1)* sumRT;
                if(i==j)    cost=0;
            }
            ans= max(ans,i-j+1);
            
        }
        
        return ans;
    }
};
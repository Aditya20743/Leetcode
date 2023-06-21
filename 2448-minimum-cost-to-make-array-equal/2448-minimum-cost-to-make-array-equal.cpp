class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long total=0;
        vector<pair<long long , long long>> v;
        for(int i=0 ; i<nums.size() ; i++){
            total+=(long long)cost[i];
            v.push_back({(long long)nums[i],(long long)cost[i]});
        }
        sort(v.begin(),v.end());
        
        // i is index at which our virtual median exists.
        int i=0;
        for(long long curr=0 ; curr+v[i].second<(total+1)/2 ; i++){
            curr+=v[i].second;
        }

        long long ans=0;
        for(int k=0;k<v.size() ; k++){
            ans+=abs(v[i].first-v[k].first)*v[k].second;
        }
        return ans;
    }
};
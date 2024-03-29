class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        int ans=0;
        
        for(auto it: mp){
            if(it.second>=2)
                ans+= it.second * (it.second-1)/2;
        }
        
        return ans;
    }
};
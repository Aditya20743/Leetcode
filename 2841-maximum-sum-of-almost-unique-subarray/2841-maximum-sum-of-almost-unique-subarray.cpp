class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long maxi = 0;
        long long sum=0;
        unordered_map<long long,long long> mp;
        
        
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            sum+= nums[i];
            if(mp.size()>=m)    maxi= sum;
        }
        
        int j=k, i=0;
        while(j<nums.size() ){
            
            mp[nums[j]]++;
            mp[nums[i]]--;
            
            if(mp[nums[i]]==0)  mp.erase(nums[i]);
            
            sum+= nums[j] - nums[i];
            
            if(mp.size()>=m)    maxi= max(sum,maxi);
            
            j++;
            i++;
        }
        
        return maxi;
    }
};

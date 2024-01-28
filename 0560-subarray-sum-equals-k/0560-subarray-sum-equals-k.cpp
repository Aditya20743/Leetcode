class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        
        int sum=nums[0];
        vector<int> prefix(n);
        prefix[0]= nums[0];
        
        unordered_map<int,int> mp;
        mp[0]=1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(i>0)
                sum= sum+ nums[i];
            // prefix[i]= prefix[i-1]+ nums[i];
            
            if(mp.find(sum-k) != mp.end() ){
                ans+= mp[sum- k];
            }
            mp[sum]++;
        }
        
        return ans;
    }
};
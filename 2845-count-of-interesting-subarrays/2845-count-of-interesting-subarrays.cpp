class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        vector<int> mod;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%modulo==k){
                mod.push_back(1);
            }
            else{
                mod.push_back(0);
            }
        }
        long long ans=0;
        unordered_map <long long, long long> mp;
        long long total = 0;
        for(int i = 0; i < nums.size();i++)
        {
            total += mod[i];
            int mod_val = total % modulo;
            if (mod_val == k) ans++;
            int find = mod_val - k;
            if (find < 0)
            {
                find += modulo;
            }
            ans += mp[find];
            mp[mod_val]++;
        }
        return ans;
        
        
    }
};
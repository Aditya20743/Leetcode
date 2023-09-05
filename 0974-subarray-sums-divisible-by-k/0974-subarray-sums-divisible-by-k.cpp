class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int total =0;
        int ans=0;
        
        for(int i=0;i<nums.size();i++){
            total+= nums[i];
            
            int mod_val= total%k;
            if(mod_val<0)   mod_val+= k;
            if(mod_val==0)  ans++;

            
            if(mp.find(mod_val)!= mp.end()){
                ans+= mp[mod_val];
            }
            mp[mod_val]++;
        }
        
        return ans;
    }
};
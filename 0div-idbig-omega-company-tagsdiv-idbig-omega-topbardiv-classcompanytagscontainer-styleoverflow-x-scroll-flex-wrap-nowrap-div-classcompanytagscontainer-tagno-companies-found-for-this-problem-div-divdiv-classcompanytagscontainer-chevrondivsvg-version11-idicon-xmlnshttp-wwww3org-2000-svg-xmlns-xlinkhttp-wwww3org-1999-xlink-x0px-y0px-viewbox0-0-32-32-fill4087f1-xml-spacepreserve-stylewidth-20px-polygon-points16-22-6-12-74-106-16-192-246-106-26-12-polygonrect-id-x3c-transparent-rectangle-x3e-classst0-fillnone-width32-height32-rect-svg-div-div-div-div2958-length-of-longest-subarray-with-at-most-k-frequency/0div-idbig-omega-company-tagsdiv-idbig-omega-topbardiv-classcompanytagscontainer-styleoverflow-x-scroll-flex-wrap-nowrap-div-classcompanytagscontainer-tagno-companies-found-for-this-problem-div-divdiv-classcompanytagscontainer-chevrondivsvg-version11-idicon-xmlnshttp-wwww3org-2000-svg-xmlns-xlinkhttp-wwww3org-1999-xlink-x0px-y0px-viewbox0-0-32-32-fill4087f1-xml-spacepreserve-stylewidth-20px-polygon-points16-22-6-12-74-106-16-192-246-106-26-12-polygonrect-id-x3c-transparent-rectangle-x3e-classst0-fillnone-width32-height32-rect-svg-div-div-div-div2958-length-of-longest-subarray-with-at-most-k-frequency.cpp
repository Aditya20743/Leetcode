class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        int r=0,l=0,maxi=0,n=nums.size();
        
        while(r<n){
            mp[nums[r]]++;
            
            if(mp[nums[r]]>k){
                while(nums[l]!= nums[r]){
                    mp[nums[l]]--;
                    l++;
                }
                mp[nums[l]]--;
                l++;
            }
            
            maxi= max(r-l+1, maxi);
            r++;
        }
        
        return maxi;
    }
};
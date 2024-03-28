class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0,r=0;
        unordered_map<int,int> mp;
        int maxi = 0;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(l<=r && mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }
            maxi =max(maxi, r-l+1);
            r++;
        }
        
        return maxi;
    }
};
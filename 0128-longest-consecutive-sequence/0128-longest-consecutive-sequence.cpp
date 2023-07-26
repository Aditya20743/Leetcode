class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        if(n==0|| n==1)    return n;
        
        map<int,int> mp;
        for(auto it: nums)  mp[it]=1;
        for(auto it: nums){
            if(mp.find(it-1)!= mp.end()){
                mp[it]=0;
            }
        }
        int maxl=0, l=0;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==1){
                while(mp.find(nums[i]+l)!= mp.end()){
                    maxl= max(l+1, maxl);
                    l++;
                }
                l=0;
            }
        }
        return maxl;
    }
};
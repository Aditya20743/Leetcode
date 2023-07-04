class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        unordered_map<int,int> mp;
        int prefix_sum=0;
        mp[0]=0;
        for(int i=1;i<=nums.size();i++){
            prefix_sum+= nums[i-1];
            mp[i]= prefix_sum;
        }
        
        for(int i=1;i<=nums.size();i++){
            if(mp[i-1]== mp[nums.size()]- mp[i]){
                return i-1;
            }
        }
        return -1;
    }
};
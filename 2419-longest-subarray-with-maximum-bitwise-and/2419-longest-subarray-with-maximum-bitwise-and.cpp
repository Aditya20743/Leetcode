class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi= *max_element(nums.begin(),nums.end());
        int n= nums.size();
        
        int count=1;
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                j=i;
                while(j<n && nums[j]==maxi){
                    j++;
                    count=max(count, j-i);
                }
                i=j;
            }
        }
        return count;
    }
};
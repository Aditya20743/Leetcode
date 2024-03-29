class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement= *max_element(nums.begin(), nums.end());
        
        int l=0,r=0,n=nums.size();
        int freqOfMaxElement=0;
        long long countOfSubarrays = 0;
        
        while(r<n){
            if(nums[r]== maxElement){
                freqOfMaxElement++;
            }
                
            while(l<=r && freqOfMaxElement>=k){
                countOfSubarrays+= n-r;
                if(nums[l]==maxElement){
                    freqOfMaxElement--;
                }
                l++;
            }

            r++;
        }
        return countOfSubarrays;
    }
};
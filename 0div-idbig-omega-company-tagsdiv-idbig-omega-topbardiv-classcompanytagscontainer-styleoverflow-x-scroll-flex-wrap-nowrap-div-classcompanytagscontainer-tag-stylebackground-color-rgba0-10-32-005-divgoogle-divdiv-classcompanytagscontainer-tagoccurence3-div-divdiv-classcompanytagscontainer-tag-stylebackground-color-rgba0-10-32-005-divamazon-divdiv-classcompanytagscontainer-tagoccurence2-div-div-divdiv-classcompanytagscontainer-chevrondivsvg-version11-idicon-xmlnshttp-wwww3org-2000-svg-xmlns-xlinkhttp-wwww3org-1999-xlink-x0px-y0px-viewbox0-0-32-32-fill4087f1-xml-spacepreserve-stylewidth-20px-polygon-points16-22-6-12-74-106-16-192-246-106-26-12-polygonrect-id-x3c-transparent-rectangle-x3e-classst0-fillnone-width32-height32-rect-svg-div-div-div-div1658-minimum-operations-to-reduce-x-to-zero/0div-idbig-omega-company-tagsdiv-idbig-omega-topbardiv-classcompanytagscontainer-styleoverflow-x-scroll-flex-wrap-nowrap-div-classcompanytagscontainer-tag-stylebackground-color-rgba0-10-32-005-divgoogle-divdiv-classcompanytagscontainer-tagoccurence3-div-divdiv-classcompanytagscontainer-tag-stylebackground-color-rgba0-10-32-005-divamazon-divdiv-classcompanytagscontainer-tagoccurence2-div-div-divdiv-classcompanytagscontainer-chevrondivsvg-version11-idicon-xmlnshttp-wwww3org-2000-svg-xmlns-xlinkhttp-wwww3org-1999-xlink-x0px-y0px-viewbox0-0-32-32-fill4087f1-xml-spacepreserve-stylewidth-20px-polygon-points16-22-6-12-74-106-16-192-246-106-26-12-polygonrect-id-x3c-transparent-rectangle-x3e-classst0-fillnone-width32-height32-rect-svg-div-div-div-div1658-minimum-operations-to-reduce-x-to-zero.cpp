class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n= nums.size();
        
        int total = 0;
        for(auto it: nums)  total+= it;
        
        int target = total - x;
        int maxi = -1, last_idx= 0;
    
        
        int curr_sum=0;
        for(int i=0;i<n;i++){
            curr_sum+= nums[i];
            
            while(curr_sum> target && last_idx<=i){
                curr_sum-= nums[last_idx];
                last_idx++;
            }
            
            if(curr_sum == target){
                maxi = max(maxi, i-last_idx+1);
            }
        }
        
        if(maxi == -1)  return -1;
        return  n- maxi;
        
        
    }
};
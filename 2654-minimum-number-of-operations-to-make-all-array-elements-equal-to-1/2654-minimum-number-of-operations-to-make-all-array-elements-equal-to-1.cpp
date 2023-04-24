class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c=0;
        for(auto it: nums){
            if(it==1)   c++;
        }
        if(c)    return nums.size()-c;
        
        int ans=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            int g= nums[i];
            for(int j=i+1;j<nums.size();j++){
                g= __gcd(g,nums[j]);
                
                if(g==1){
                    int n=nums.size();
                    ans= min(ans,j-i+(n-1));
                }
            }
        }
        return ans==INT_MAX ? -1: ans; 
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n= nums.size();
        // for(auto it: nums){
        //     sum+= it;
        // }
        // return n*(n+1)/2 - sum;
        
        int xorr=n;
        for(int i=0;i<n;i++){
            xorr= xorr^nums[i];
            xorr^= i;
        }
        return xorr;
    }
};
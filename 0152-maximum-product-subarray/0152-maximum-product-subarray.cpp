class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxiprod=INT_MIN;
        
        int mini=1, maxi=1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                swap(maxi,mini);
            }
            
            maxi= max(maxi*nums[i], nums[i]);
            mini= min(mini*nums[i], nums[i]);
            
            maxiprod= max(maxiprod, maxi);
        }
        return maxiprod;
    }
};
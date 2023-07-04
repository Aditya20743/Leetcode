class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0,maxi=0;
        
        for(int i=0;i<k;i++){
            sum+= (nums[i]*1.0)/k;
        }
        maxi= sum;
        int j=k,i=0,n=nums.size();
        while(j<n){
            sum+= (nums[j++]*1.0 - nums[i++]*1.0)/k;
            maxi= max(maxi,sum);
        }
        return maxi;
    }
};
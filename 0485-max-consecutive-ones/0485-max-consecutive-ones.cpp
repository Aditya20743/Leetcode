class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=1;
        int maxi=0;
        // if(nums.size()==1){
        //     if(nums[0]==0){
        //         return 0;
        //     }
        //     else{
        //         return 1;
        //     }
        // }
        if(nums[0]==1){
            maxi=1;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]== nums[i-1] && nums[i]==1){
                c++;
            }
            else if(nums[i]==1){
                c=1;
            }
            else{
                c=0;
            }
            maxi= max(maxi,c);
        }
        return maxi;
    }
};
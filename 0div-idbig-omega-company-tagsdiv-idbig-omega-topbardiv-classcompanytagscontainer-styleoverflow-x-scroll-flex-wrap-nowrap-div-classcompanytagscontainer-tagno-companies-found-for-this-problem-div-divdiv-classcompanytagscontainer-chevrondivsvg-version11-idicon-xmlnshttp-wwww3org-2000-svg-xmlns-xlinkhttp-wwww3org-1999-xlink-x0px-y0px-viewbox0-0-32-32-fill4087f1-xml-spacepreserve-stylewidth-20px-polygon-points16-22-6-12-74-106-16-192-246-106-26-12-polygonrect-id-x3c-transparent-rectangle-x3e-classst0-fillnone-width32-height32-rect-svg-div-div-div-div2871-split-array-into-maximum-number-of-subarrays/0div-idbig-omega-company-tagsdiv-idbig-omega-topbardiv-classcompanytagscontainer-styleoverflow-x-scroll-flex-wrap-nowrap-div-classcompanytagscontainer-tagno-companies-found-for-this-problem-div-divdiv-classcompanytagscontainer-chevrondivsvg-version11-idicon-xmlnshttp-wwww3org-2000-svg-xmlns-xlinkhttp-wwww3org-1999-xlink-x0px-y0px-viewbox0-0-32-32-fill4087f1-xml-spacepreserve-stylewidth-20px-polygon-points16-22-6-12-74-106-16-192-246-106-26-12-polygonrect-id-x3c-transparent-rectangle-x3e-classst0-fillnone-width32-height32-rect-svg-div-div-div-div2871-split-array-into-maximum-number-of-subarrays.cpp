class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int i=0,ans=0;
        int temp=INT_MAX;
        while(i<nums.size()){
            if(nums[i]==0){
                ans++;
                temp= INT_MAX;
            }
            else{
                temp = temp & nums[i];
                // cout<<temp<<endl;
                if(temp==0){
                    ans++;
                    temp= INT_MAX;
                }
            }
            i++;
        }
        
    return ans==0 ? 1: ans;
    }
};
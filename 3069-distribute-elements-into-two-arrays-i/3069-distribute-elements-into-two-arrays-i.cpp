class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int l=0,r=1;
        
        vector<int> ans1, ans2;
        ans1.push_back(nums[0]);
        ans2.push_back(nums[1]);
        
        for(int i=2;i<nums.size();i++){
            if(nums[l]>nums[r]){
                ans1.push_back(nums[i]);
                l=i;
            }
            else{
                ans2.push_back(nums[i]);
                r=i;
            }
        }
        
        for(auto it: ans2){
            ans1.push_back(it);
        }
        return ans1;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){

            int t=-nums[i];
            int low=i+1, high=n-1;
            
            while(low<high){
                if(nums[low]+nums[high]==t){
                    s.insert({-t,nums[low],nums[high]});
                    low++;
                    high--;
                }
                else if( nums[low]+nums[high]<t){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        for(auto it: s){
            ans.push_back(it);
        }
        return ans;
    }
};
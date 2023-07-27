class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        for(int i=0 ;i<n;i++){
            int f= nums[i];
            int l= i+1, h= n-1;
            while(l<h){
                if(nums[l]+ nums[h]+ f == 0){
                    s.insert({f, nums[l], nums[h]});
                    l++;
                    h--;
                }
                else if(nums[l]+ nums[h] + f >0){
                    h--;
                }
                else{
                    l++;
                }
            }
        }
        for(auto it: s) ans.push_back(it);
        return ans;
    }
};
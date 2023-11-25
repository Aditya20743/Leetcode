class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n= nums.size();
        
        vector<int> prefix(n);
        vector<int> ans(n);
        
        prefix[0]= nums[0];
        
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        
        for(int i=0;i<n;i++){
            ans[i] = (prefix[n-1] - prefix[i]) - (nums[i]*(n-1-i));
            ans[i] += (nums[i]*(i+1) - prefix[i]);
        }
        
        return ans;
        
    }
};
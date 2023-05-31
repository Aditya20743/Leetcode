class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>v;
        int n=nums.size();
        // if(n==1){
        //     return nums;
        // }
        k= k%n;
        for(int i=n-k;i<n;i++){
            v.push_back(nums[i]);
        }
        for(int i=n-k-1;i>=0;i--){
            nums[(i+k)%n]= nums[i];
        }
        
        for(int i=0;i<k;i++){
            nums[i]= v[i];
        }
    }
};
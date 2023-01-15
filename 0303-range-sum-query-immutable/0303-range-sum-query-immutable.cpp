class NumArray {
public:
    vector<int> presum;
    NumArray(vector<int>& nums) {
        vector<int> x(nums.size()+1);
        x[0]=0;
        for(int i=1;i<=nums.size();i++){
            x[i]=x[i-1]+nums[i-1];
        }
        presum= x;
    }
    
    int sumRange(int left, int right) {
        // for(auto it: presum){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return presum[right+1]-presum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
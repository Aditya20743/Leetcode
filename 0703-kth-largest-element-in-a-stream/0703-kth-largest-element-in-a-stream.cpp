class KthLargest {
public:
    priority_queue<int, vector<int> , greater<int> > mxh;
    int x;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            mxh.push(nums[i]);
            if(mxh.size()>k)    mxh.pop();
        }
       
        x=k;
    }
    
    int add(int val) {
        mxh.push(val);
        if(mxh.size()>x)
        mxh.pop();
        int ans= mxh.top();
        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
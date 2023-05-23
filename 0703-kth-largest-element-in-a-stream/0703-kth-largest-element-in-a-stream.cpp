class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > pq;
    int q=0;
    KthLargest(int k, vector<int>& nums) {
        q=k;
        for(auto it: nums){
            pq.push(it);
            if(pq.size()>q){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>q){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
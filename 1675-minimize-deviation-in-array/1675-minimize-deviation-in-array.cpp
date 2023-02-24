class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mn=INT_MAX, mx=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                nums[i]*=2;
            }
            mn= min(mn,nums[i]);
            mx= max(mx,nums[i]);
        }
        int dif= mx-mn;
        
        priority_queue<int> pq;
        for(auto it: nums)  pq.push(it);
        
        while(pq.top()%2==0){
            int x= pq.top();
            pq.pop();
            dif=min(dif, x- mn);
            x/=2;
            mn= min(x, mn);
            pq.push(x);
        }
        dif= min(dif,pq.top()-mn);
        return dif;
    }
};
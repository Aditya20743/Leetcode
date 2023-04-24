class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it: stones){
            pq.push(it);
        }
        while(pq.size()>1){
            int t= pq.top();
            pq.pop();
            int r= pq.top();
            pq.pop();
            if(t>r){
                pq.push(t-r);
            }
        }
        if(pq.size()==1){
            int ans= pq.top();
            return ans;
        }
        return 0;
    }
};
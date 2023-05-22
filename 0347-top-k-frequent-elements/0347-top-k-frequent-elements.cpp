class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        
        for(auto it: mp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();   
            }
        }
        while(!pq.empty()){
            int freq= pq.top().first;
            int no= pq.top().second;
            
            ans.push_back(no);
            pq.pop();
        }
        return ans;
    }
};
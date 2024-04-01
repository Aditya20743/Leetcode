class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long> ans;
        unordered_map<int, long long> mp;
        priority_queue<pair<long long,int>> pq;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] += freq[i];
            pq.push({mp[nums[i]],nums[i]});
            
            while(!pq.empty()){
                pair<long long, int> topFreqPair = pq.top();
                
                if(topFreqPair.first != mp[topFreqPair.second]){
                    pq.pop();
                }
                else{
                    break;
                }
            }
            
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
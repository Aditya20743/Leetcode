class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> store;
        for(auto it: nums){
            if(store.empty() || store.back()<it){
                store.push_back(it);
            }
            else{
                auto t= lower_bound(store.begin(), store.end(), it);
                *t= it;
            }
        }
        return store.size();
    }
};

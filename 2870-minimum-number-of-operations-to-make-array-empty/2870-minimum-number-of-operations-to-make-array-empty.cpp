class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it: nums)  mp[it]++;
        
        int ans=0;
        for(auto it: mp){
            if(it.second==1){
                return -1;
            }
            else if(it.second%3==0){
                ans+= it.second/3;
                // it.second=0;
            }
            else if(it.second==2){
                ans+= 1;
                // it.second=0;
            }
            else if(it.second%3==2){
                ans+= it.second/3 +1;
                // it.second=0;
            }
            else if(it.second==4){
                ans+= 2;
            }
            else if(it.second%3==1){
                ans+= (it.second-4)/3 +2;
            }
        }
        return ans;
    }
};
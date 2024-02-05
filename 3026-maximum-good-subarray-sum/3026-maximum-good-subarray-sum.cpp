class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<long long> prefix;
        long long s=0;
        prefix.push_back(0);
        for(int i=0;i<nums.size();i++){
            s+= nums[i];
            prefix.push_back(s);
        }
        long long maxi=LLONG_MIN;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-k)!= mp.end()){
                maxi= max(maxi, prefix[i+1]- prefix[ mp[ nums[i]-k ] ] );
                // cout<<maxi<<endl;
            }
            if(mp.find(k + nums[i])!= mp.end()){
                // cout<<111<<endl;
                maxi= max(maxi, prefix[i+1]- prefix[ mp[ k+nums[i] ] ] );
                // cout<<maxi<<endl;
            }
            
            if(mp.find(nums[i])!= mp.end()){
                if(prefix[mp[nums[i]] +1] > prefix[i+1]){
                    mp[nums[i]] =i;
                }
                // else{
                //     cout<<mp[nums[i]];
                // }
            }
            else{
                mp[nums[i]] = i;
            }
        }
        // cout<<mp[7];
        if(maxi == LLONG_MIN)     return 0;
        return maxi;
    }
};
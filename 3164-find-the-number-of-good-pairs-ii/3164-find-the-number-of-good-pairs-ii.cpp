class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long n= nums1.size();
        long long m= nums2.size();
        
        unordered_map<long long,long long> mp;
        
        for(auto num: nums1){
            for(int i=1;i*i<=num;i++){
                if(i*i == num){
                    mp[i]++;
                }
                else if(num % i == 0){
                    mp[i]++;
                    mp[num/i]++;
                }
            }
        }
        long long ans=0;
        
        for(auto num: nums2){
            ans+= mp[1LL*num*k];
            // cout<<ans<<" "<<num<<" "<<endl;
        }
        return ans;
    }
};
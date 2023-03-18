class Solution {
public:
    // static bool comp(pair<long long,long long>&a,pair<long long,long long>&b){
    //     if(a.first==b.first)return a.second<b.second;
    //     return a.first<b.first;
    // }
    #define ll long long
    long long findScore(vector<int>& nums) {
        vector<pair<ll,ll>> v(nums.size());
        for(int i=0;i<nums.size();i++){
            v[i]= {nums[i],i};
        }
        
        vector<ll> unm(nums.size(),0);
        
        sort(v.begin(),v.end());
        
        ll idx=0,c=0,ans=0;
        while( idx< nums.size()){
            ll ele= v[idx].first;
            ll index= v[idx].second;
            
            if(unm[index]==0){
            ans+= ele;
            unm[index]=1;
            if(index-1 != -1)
                unm[index-1]=1;
                
            if(index+1 != nums.size())
                unm[index+1]=1;
             }
            idx++;
        }
        return ans;
    }
};
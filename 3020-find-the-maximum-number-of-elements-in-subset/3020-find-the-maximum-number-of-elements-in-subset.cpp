class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        
        map<int,int> mp;
        
        for(auto it: nums){
            mp[it]++;
        }
        int ans=0;
        
        for(auto it: mp){
            long long num= it.first;
            int freq= it.second;
            
            int count= 0;
            
            if(num==1){
                if(freq%2==0){
                    count= (freq-1);
                }
                else    count= freq;
                mp[num]=0;
            }
            
            while(num<INT_MAX && mp[num]>0){
                
                count+=2;
                if(mp[num]==1){
                    count--;
                    break;
                }
                mp[num]=0;
                num= num* num;
               
            }
            if(count%2==0)  count--;
            ans= max(count, ans);
            
        }
        return ans;
        
    }
};
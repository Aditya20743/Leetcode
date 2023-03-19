class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            // while(nums[i]<0){
            //     nums[i]+= value;
            // }
            if(nums[i]%value<0){
                nums[i]= nums[i]%value+ value;
            }
            else nums[i]= nums[i]%value;
        }
        for(auto it: nums)  cout<<it<<" ";
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        
        int c=0,i=0;
        while(c<nums.size()){
            if(mp[c%value]>0){
                mp[c%value]--;
                if(mp[c%value]==0)    mp.erase(c%value);
                c++;
            }
            else{
                break;
            }
        }
        return c;
    }
};
class Solution {
public:
    long long maxsum(vector<int> nums){
        long long s= 0;
        long long a= INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            s+= nums[i];
            a=max(s,a);
            if(s<0) s=0;
        }
        return a;
    }
    long long minsum(vector<int> nums){
        long long s= 0;
        long long a= INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            s+= nums[i];
            a=min(s,a);
            if(s>0) s=0;
        }
        return a;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        long long maxs= maxsum(nums);
        long long mins= minsum(nums);
        
        long long sum=0;
        for(int i=0;i<nums.size();i++)  sum+=nums[i];
        
        long long cirs= sum- mins;
        
        cout<<"maxs-"<<maxs<<"mins-"<<mins<<"cirs-"<<cirs<<endl;
        if(maxs>0)    return max(cirs,maxs);
        return maxs;
    }
};
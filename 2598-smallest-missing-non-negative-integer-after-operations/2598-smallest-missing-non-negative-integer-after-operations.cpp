class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        
        map<int,int> mp;
        if(value==1) return nums.size();
        for(int i=0;i<nums.size();i++){
            while(nums[i]<0){
                nums[i]= nums[i]%value + value;
            }
            nums[i]= nums[i]%value;
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[i%value]==0){
                return i;
            }
            else{
                mp[i%value]--;
            }
        }
        return nums.size();
    }
};
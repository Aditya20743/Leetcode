class Solution {
public:
    // Brute force
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        if(n==0)    return 0;
        int c=1;
        int maxi=1;
        for(int i=1;i<n;i++){
            if(nums[i]== nums[i-1]+1){
                c++;
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                maxi= max(maxi , c);
                c=1;
            }
        }
        if(c!= 1){
            maxi= max(maxi,c);
        }
        return maxi;
    }
};
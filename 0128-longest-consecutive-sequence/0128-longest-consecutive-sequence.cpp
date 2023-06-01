class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        
        unordered_set<int> s;
        for(auto num: nums){
            s.insert(num);
        }
        
        int maxi=1,streak=1;
        for(auto num: nums){
            if(!s.count(num-1)){
                int cnum= num+1;
                streak=1;
                while(s.count(cnum)){
                    streak++;
                    cnum++;
                }
                maxi=max(maxi, streak);
                streak=0;
            }
        }
        return maxi;
    }
};
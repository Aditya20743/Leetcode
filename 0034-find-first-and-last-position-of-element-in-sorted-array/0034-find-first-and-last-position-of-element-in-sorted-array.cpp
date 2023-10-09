class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,h= nums.size()-1;
        vector<int> ans;
        int first= INT_MAX;
        while(l<=h){
            int m= l + (h-l)/2;
            
            if(nums[m]> target){
                h= m-1;
            }
            else if(nums[m] < target){
                l = m+1;
            }
            else{
                int t=m;
                first= m;
                int fi,si;
                while(t>=0 && nums[t]== target){
                    fi= t;
                    t--;
                }
                int s= m;
                while(s<nums.size() && nums[s]== target){
                    si =s;
                    s++;
                }
                ans={fi,si};
                break;
            }
            
        }
        
        if(first== INT_MAX){
            ans = {-1,-1};
        }
        
        return ans;
    }
};
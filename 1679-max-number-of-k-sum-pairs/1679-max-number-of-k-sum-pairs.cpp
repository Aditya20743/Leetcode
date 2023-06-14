class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0, r=nums.size()-1;
        int count=0;
        unordered_set<int> s;
        while(l<=r){
            if(nums[l]+ nums[r]==k){
                // nums.erase(nums.begin()+r);
                // nums.erase(nums.begin()+l);
                
                if(!(s.find(r)!=s.end() || s.find(l)!=s.end()) && r!=l){
                    s.insert(r);
                    s.insert(l);
                    // cout<<r<<" "<<l<<endl;
                    count++;
                }
                r--;
                l++;
                // cout<<1<<endl;
            }
            else if(nums[l]+nums[r]>k){
                r--;
            }
            else if(nums[l]+nums[r]<k){
                l++;
            }
        }
        // for(auto it: s){
        //     cout<<it<<endl;
        // }
        return count;
    }
};
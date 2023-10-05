class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1=INT_MAX,m2=INT_MAX;
        int c1=0,c2=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]==m1){
                c1++;
            }
            else if(nums[i]==m2){
                c2++;
            }
            else if(c1==0){
                m1=nums[i];
                c1=1;
            }
            else if(c2==0){
                m2=nums[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        double req= n/3.0;
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==m1){
                c1++;
            }
            else if(nums[i]==m2){
                c2++;
            }
        }
        
        vector<int> ans;
        if(c1> req)     ans.push_back(m1);
        if(c2>req)  ans.push_back(m2);
        return ans;
    }
};
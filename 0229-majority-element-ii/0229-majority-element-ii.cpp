class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0, c2=0, n= nums.size();
        int maxi1=-1, maxi2=-1;
        
        for(int i=0;i<n;i++){
            if(nums[i]== maxi1){
                c1++;
            }
            else if(nums[i]==maxi2){
                c2++;
            }
            else if(c1==0){
                maxi1= nums[i];
                c1++;
            }
            else if( c2==0){
                maxi2= nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        // cout<<maxi1<<" "<<maxi2<<endl;
        vector<int> ans;
        
        c1=0;
        c2=0;
        int t= floor(n/3.0);
        
        for(auto num: nums){
            if(num== maxi1){
                c1++;
            }
            else if(num==maxi2){
                c2++;
            }
        }
        if(c1>t)    ans.push_back(maxi1);
        if(c2>t)    ans.push_back(maxi2);
        return ans;
    }
};
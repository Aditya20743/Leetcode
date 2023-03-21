class Solution {
public:
    
    long long zeroFilledSubarray(vector<int>& nums) {
        //vector< long long > v(nums.size());
        // v[1]=1;
        // v[2]= 3;
        // for(int i=1;i<nums.size();i++){
        //     v[i]= i*(i+1)/2;
        // }
        long long c=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                c++;
            }
            else if(nums[i]){
                if(c>0){
                    cout<<c<<" ";
                    ans+= c*(c+1)/2;
                    c=0;
                }
            }
            
        }
        if(c>0){
                    cout<<c<<" ";
                    ans+= c*(c+1)/2;
                    c=0;
                }
        return ans;
    }
};
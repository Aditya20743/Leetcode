class Solution {
public:
    int minimumOperations(string nums) {
        int n= nums.size();
        int ans=n;
        
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                int no = nums[i]-'0' + (nums[j]-'0')*10;
                if(no%25==0){
                    ans= min(ans, i-j-1 + n-1-i);
                }
            }
            if(nums[i]=='0'){
                ans = min(ans, n-1);
            }
        }
        return ans;
    }
};
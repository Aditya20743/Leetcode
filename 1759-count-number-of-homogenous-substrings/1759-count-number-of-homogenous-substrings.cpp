class Solution {
public:
    int countHomogenous(string s) {
        long long ans=0,c=1,mod=1e9+7;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                c++;
            }
            else if(s[i]!= s[i-1]){
                ans+= (c*(c+1)/2)%mod;
                c=1;
            }
        }
        ans+= (c*(c+1)/2)%mod;
        return ans;
    }
};
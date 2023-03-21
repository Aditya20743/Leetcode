class Solution {
public:
    int numSub(string s) {
        
        long long ans=0,mod= 1e9+7,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                c++;
            }
            else if(s[i]!= '1'){
                ans+= (c*(c+1)/2)%mod;
                c=0;
            }
        }
        if(c){
            ans+= (c*(c+1)/2)%mod;
            c=0;
        }
        return ans%mod;
    }
};
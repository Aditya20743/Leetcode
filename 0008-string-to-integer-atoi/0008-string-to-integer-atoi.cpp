class Solution {
public:
    int myAtoi(string s) {
        int i=0, n=s.size();
        long long ans=0;
        bool f=true;
        
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            if(s[i]=='-'){
                f=false;
                i++;
            }
            else if(s[i]=='+'){
                i++;
            }
            while(i<n && s[i]>='0' && s[i]<='9'){
                // cout<<ans<<endl;
                
                ans= ans*10+ (s[i]-'0');
                if(ans >= INT_MAX && f== true)   return INT_MAX;
                if(ans > INT_MAX && f==false)   return INT_MIN;
                i++;
            }
            if(f==false)
                return -1*(int)ans;
            else
                return (int)ans;
        }
        return ans;
    }
};
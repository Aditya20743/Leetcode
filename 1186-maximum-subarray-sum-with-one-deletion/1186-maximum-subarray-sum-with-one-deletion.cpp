class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n= arr.size();
        vector<int> f(n), b(n);
        
        int cs=0, s=arr[0];
        for(int i=0;i<n;i++){
            cs+= arr[i];
            s= max(cs, s);
            if(cs<0){
                cs =0;
            }
            
            f[i]= cs;
            // cout<<f[i];
        }
        cs=0;
        for(int i=n-1;i>=0;i--){
            cs+= arr[i];
            b[i]= cs;
            s= max(cs, s);
            if(cs<0){
                cs =0;
            }
            
            // cout<<b[i];
        }
        int ans=s;
        for(int i=1;i<n-1;i++){
            ans = max( ans, f[i-1]+ b[i+1]);
        }
        return ans;
    }
};
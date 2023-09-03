class Solution {
public:
    int mod = 1000000007;
    
    long long power(int x, int n) {
        if( n == 0) return 1;
        
        long long ans = power(x, n / 2);
        ans *= ans;
        ans %= mod;
        
        if(n % 2 != 0) {
            ans *= x;
            ans %= mod;
        }
         
        return ans;
    }
    
    long long fact(int n) {
        long long ans = 1;
        
        for(int i = 1; i <= n; i++) {
            ans *= i;
            ans %= mod;
        }
        
        return ans;
    }
    
    long long nCr(int n, int r) {
        long long ans = fact(n);
        long long denominator = (fact(r) * fact(n - r)) % mod;
        
        return (ans * power(denominator, mod - 2)) % mod;
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        
        priority_queue<int> pq;
        
        vector<int> freq(26,0);
        
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(freq[i]>0)
                pq.push(freq[i]);
        }
        
        if(pq.size()<k) return 0;
        
        long long ans=1;
        
        while(k){
            int last_num= pq.top();
            int same_num= 0;
            
            while(pq.size()>0 && pq.top()== last_num){
                same_num++;
                pq.pop();
            }
            
            if(same_num<=k){
                ans= (ans *power(last_num, same_num))%mod;
                k-= same_num;
                // normal multiplication

            }
            else{
                ans= (ans* nCr(same_num, k))%mod;
                ans= (ans* power(last_num, k))%mod;
                k=0;
                // multiply and ncr
            }
        }
        return ans;
        
        
        
//         long long t= 1e9+7;
        
//         unordered_map<char,int> mp;
//         for(auto it: s){
//             mp[it]++;
//         }
//         vector<int> v;
//         for(auto it: mp){
//             v.push_back(it.second);
//         }
//         sort(v.begin(),v.end());
//         int i= v.size()-1;
//         if(v.size()<k)  return 0;
//         int max=0;
//         int l=-1;
//         long long ans=1;
//         while(k--){
//             max+= v[i];
//             ans = (ans*v[i])%t;
//             l= v[i];
//             i--;
//         }
//         int j=-1;
//         for(j=v.size()-1;j>=0;j--){
//             if(v[j]==l) break;
//         }
        
        
//         vector<int> store;
//         while(i>0 && v[i]==l){
//             store.push_back(v[i]);
//             i--;
//         }
        
//         int z= store.size();
        
// //         if(l == v[0]){
            
// //         }
//         if(i==j){
//             return ans;
//         }
        
//         int n= v.size() - 1 - (j);
//         //  shudh
//         i = v.size()-1;
//         int c=n;
//         ans=1;
//         while(i-- & c--){
//             ans= (ans* v[i])%t;
//         }
//         long long temp= nCr(z,k-n);
        
//         ans= ans*  pow(v[0],temp);
        
//         return ans;
        
        
    }
};
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    // long long fac(int i){
    //     long long sum=0;
    //     for(int j=1;j<=i;j++){
    //         if(i%j==0){
    //             sum+= j;
    //         }
    //     }
    //     return sum;
    // }
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        // vector<long long> dp(N+1);
        // dp[1]=1;
        // for(int i=2;i<=N;i++){
        //     dp[i]= dp[i-1]+ fac(i);
        // }
        // return dp[N];
        long long sum=0;
        for(int i=1;i<=N;i++){
           sum+= i * (N/i); 
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends
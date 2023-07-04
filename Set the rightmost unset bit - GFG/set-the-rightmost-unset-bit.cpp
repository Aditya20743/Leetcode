//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {   int ans=N;
        // Write Your Code here
        int bits= log2(N);
        for(int i=0;i<=bits;i++){
            int temp= N & 1<<i;
            if(temp==0){
                ans= N | 1<<i; 
                break;
            }
        }
        // if(ans>N)   return N;
        return ans;
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
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
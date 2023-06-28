//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int prefixsum=0;
        int ans=0;
        mp[0]=-1;
        
        for(int i=0;i<n;i++){
            
            prefixsum+= A[i];
            if(mp.find(prefixsum)== mp.end()){
                mp[prefixsum]=i;
            }
            // else if(prefixsum==0){
            //     ans= max(ans, i);
            // }
            else{
                ans= max(ans, i-mp[prefixsum]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
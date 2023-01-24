//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        priority_queue<long long> mh;
        long long sum=0,sum2=0;
        for(int i=0;i<N;i++){
            mh.push(A[i]);
            sum+= A[i];
            if(mh.size()>K1){
                sum-= mh.top();
                mh.pop();
            }
        }
        while(!mh.empty()){
            sum+= mh.top();
            mh.pop();
        }
        
        for(int i=0;i<N;i++){
            mh.push(A[i]);
            sum2+= A[i];
            if(mh.size()>K2-1){
                sum2-= mh.top();
                mh.pop();
            }
        }
        while(!mh.empty()){
            sum2+= mh.top();
            mh.pop();
        }
        long long ans= (sum2-sum)/2;
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    int maxi= a[0];
	    int curr=0;
	    int s=0,st,en;
	    for(int i=0;i<n;i++){
	        if(a[i]>=0)
	            curr+= a[i];
	        else{
	            curr=0;
	            s= i+1;
	        }
	        if(maxi< curr){
	            maxi= curr;
	            st= s;
	            en= i;
	        }
	        else if(maxi== curr){
	            if(en - st < i - s){
	                en= i;
	                st= s;
	            }
	        }
	        
	        if(curr<0){
	            s= i+1;
	            curr=0;
	        }
	    }
	    vector<int> ans;
	    for(int i= st;i<= en ;i++){
	        ans.push_back(a[i]);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
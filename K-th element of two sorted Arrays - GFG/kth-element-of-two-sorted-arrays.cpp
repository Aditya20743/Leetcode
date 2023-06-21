//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int c=0;
        int i=0, j=0;
        
        while(i<n && j<m && c!=k-1){
            if(arr1[i]< arr2[j]){
                c++;
                i++;
            }
            else {
                c++;
                j++;
            }
        }
        if(c==k-1 && i<n && j<m){
            if(arr1[i]< arr2[j]){
                return arr1[i];
            }
            else return arr2[j];
        }
        
        else if(i==n){
            while(c!= k-1){
                arr2[j++];
                c++;
            }
            return arr2[j];
        }
        else if(j==m){
            while(c!= k-1){
                arr1[i++];
                c++;
            }
            return arr1[i];
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        vector<int> steps(1e5+1,INT_MAX);
        steps[start]=0;
        int mod= 1e5;
        q.push({0,start});
        
        while(!q.empty()){
            int step= q.front().first;
            int no= q.front().second;
            if(no== end)    return step;
            q.pop();
            
            for(auto it: arr){
                int newno= (it* no)%mod;
                if(steps[newno]> step+1){
                    steps[newno]= step+1;
                    q.push({steps[newno],newno});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

# define ll long long int
class Solution {
  public:
    
    bool check(ll m, vector<int>& piles, int H){
        ll total_time=0;
        for(auto it: piles){
            total_time+= ceil(1.0*it/m);
        }
        if(total_time<= H)  return true;
        return false;
        //return total_time<=H;
    }
    
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        ll h= *max_element(piles.begin(),piles.end());
        ll l=1,m=0;
        
        while(l<=h){
            ll m= l+(h-l)/2;
            
            if(check(m,piles,H)){
                h= m-1;
            }
            else{
                l= m+1;
            }
        }
        return h+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
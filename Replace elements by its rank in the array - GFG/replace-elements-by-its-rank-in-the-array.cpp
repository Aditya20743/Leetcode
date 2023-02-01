//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        vector<pair<int,int>> v;
        int c=0;
        for(auto it: arr){
            pair<int,int> p;
            p.first= it;
            p.second= c++;
            
            v.push_back(p);
        }
        sort(v.begin(),v.end());
        
        vector<int> ans(N);
        int idx=0;
        for(int i=0;i<N;i++){
            if(i>0 && v[i].first== v[i-1].first)    idx--;
            ans[v[i].second]= idx+1;
            idx++;
        }
        return ans;

    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void helper( int r,int c, vector<vector<int>> &m, int n, 
    vector<string>& ans, string s){
        int dir[5]={-1,0,1,0,-1};
        string d="URDL";
        
        if(r== n-1 && c== n-1){
            ans.push_back(s);
            s.erase(s.begin(),s.end());
        }
        for(int i=0;i<4;i++){
            int nr= dir[i]+ r;
            int nc= dir[i+1]+ c;
            
            if(nr>=0 && nr< n && nc>=0 && nc<n && m[nr][nc]==1){
                s.push_back(d[i]);
                m[nr][nc]=0;
                helper(nr,nc,m,n, ans, s);
                m[nr][nc]=1;
                s.pop_back();
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string s;
        
        if(m[0][0]==0)  return ans;
        m[0][0]=0;
        helper(0, 0, m, n, ans, s);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
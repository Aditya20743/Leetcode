//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private: 
    vector<int>topoSort(vector<int>adj[], int K){
        vector<int> v;
        queue<int> q;
        int indeg[K];
        for(int i=0;i<K;i++) indeg[i]=0;
        
        for(int i=0;i<K;i++){
            for(auto it: adj[i]){
                indeg[it]++;
            }
        }
        
        
        for(int i=0;i<K;i++){
            if(indeg[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int n= q.front();
            q.pop();
            v.push_back(n);
            
            for(auto it: adj[n]){
                indeg[it]--;
                if(indeg[it]==0)    q.push(it);
            }
        }
        return v;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i=0;i<N-1;i++){
            string a= dict[i];
            string b= dict[i+1];
            
            int len= min(a.size(),b.size());
            for(int ptr= 0; ptr<len; ptr++){
                if(a[ptr]!= b[ptr]){
                    adj[a[ptr]-'a'].push_back(b[ptr]-'a');
                    break;
                }
            } 
        }
        
        vector<int> topo = topoSort(adj,K);
        string ans="";
        for(auto it: topo){
            ans+= char(it+'a');
        }
        // cout<<ans;
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
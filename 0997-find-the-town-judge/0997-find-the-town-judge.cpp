class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int>mp, np;
        
        for(int i=0;i<trust.size();i++){
            mp[trust[i][0]]++;
        }
        vector<int> v;
        for(int i=1;i<=n;i++){
            if(mp[i]==0){
                v.push_back(i);
            }
        }
        if(v.empty()) return -1;
        cout<<v.back();
        int c=0;
        if(v.size()>=2) return -1; 
        for(int i=0;i<trust.size();i++){
            if(trust[i][1]==v.back()){
                c++;
            }
        }
        if(c==n-1)  return v.back();
        return -1;
        
        
        
//         vector<vector<int>> adj;
        
//         for(int i=0;i<n;i++){
//             for(auto it: trust){
//                 adj[it[0]].push_back(it[1]);
//             }
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<adj[i].size();j++)
//                 cout<<adj[i][j];
//             cout<<endl;
//         }
//         int indeg[n];
//         for(int i=0;i<n;i++)    indeg[i]=0;
        
//         for(int i=0;i<n;i++){
//             for(auto it: adj[i]){
//                 indeg[it]++;
//             }
//         }
//         queue<int> q;
        
//         for(int i=0;i<n;i++){
//             if(indeg[i]==0) q.push(i);
//         }
//         vector<int> topo;
//         while(!q.empty()){
//             int node= q.front();
//             q.pop();
//             topo.push_back(node);
            
//             for(auto it: adj[node]){
//                 indeg[it]--;
//                 if(indeg[it]==0)    q.push(it);
//             }
//         }
//         return topo.back();
        return 1;
    }
};
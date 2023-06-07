class Solution {
public:
//     static bool comp(int a ,int b){
//         string x= to_string(a);
//         string y= to_string(b);

//         for(int i=0;i<min(x.size(),y.size());i++){
//             if(x[i]< y[i]){
//                 return true;
//             }
//             else if(x[i]>y[i]){
//                 return false;
//             }
//         }
//         if(x.size()<y.size()){
//             return true;
//         }
//         return false;
//     }
    void dfs(int sum,vector<int>&ans, int n){
        if(sum>n)   return;
        
        for(int i=0;i<=9;i++){
            if(sum*10+i <= n){
                ans.push_back(sum*10+i);
            }
            dfs(sum*10+i,ans, n);
        }
        
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int sum=0;
        for(int i=1;i<=9;i++){
            if(i<=n){
                ans.push_back(i);
            }
            dfs(sum*10+i,ans,n);
        }
        // sort(ans.begin(),ans.end(),comp);
        
        return ans;
    }
};
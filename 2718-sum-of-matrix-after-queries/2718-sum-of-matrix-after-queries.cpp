class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long ans=0;
        long long z= queries.size();
        long long row= 0,col=0;
        unordered_map<int,int> mprow, mpcol;
        
        for(int i=z-1;i>=0;i--){
            if(queries[i][0]==0 && mprow.count(queries[i][1])==0){
                ans+= (n-col)* queries[i][2];
                mprow[queries[i][1]]++;
                row++;
            }
            // else if(queries[i][0]==0 && mprow.count(queries[i][1])){
            //     cout<<"mprow"<<endl;
            //     cout<<mprow[queries[i][1]]<<endl;
            // }
            else if(queries[i][0]==1 && mpcol.count(queries[i][1])==0){
                ans+= (n-row)* queries[i][2];
                mpcol[queries[i][1]]++;
                col++;
            }
//             else if(queries[i][0]==1 && mpcol.count(queries[i][1])){
//                 cout<<"mpcol"<<endl;

//             }
//             cout<<ans<<" "<<endl;
        }
        return ans;
        
    }
};
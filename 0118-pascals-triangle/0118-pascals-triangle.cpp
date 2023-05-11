class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        vector<int> temp;
        ans.push_back({1});
        
        for(int i=1;i<numRows;i++){
            for(int j=0;j<=i;j++){
                int t=0;
                if(j<i){
                    t+= ans[i-1][j];
                }
                if(j>0){
                    t+= ans[i-1][j-1];
                }
                temp.push_back(t);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};
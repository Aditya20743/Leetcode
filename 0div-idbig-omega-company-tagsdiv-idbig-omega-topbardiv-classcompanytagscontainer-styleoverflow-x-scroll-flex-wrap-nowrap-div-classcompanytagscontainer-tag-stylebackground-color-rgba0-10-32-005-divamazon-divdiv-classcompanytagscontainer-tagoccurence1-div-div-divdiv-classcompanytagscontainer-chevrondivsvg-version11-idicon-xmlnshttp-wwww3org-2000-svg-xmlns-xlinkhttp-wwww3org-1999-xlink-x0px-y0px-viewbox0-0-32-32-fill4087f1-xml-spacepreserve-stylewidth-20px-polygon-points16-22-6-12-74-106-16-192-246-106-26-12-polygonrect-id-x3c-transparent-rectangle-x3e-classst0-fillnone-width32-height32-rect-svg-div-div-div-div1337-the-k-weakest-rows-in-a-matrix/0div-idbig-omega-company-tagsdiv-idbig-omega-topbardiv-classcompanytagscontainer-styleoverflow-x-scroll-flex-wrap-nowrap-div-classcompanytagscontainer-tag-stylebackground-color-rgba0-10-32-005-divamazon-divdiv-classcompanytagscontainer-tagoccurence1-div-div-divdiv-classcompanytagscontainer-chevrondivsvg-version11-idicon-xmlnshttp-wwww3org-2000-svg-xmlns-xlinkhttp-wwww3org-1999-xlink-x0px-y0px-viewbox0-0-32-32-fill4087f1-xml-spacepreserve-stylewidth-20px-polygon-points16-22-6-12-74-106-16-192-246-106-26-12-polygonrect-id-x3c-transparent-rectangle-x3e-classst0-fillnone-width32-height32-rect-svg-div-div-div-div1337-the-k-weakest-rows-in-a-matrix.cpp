class Solution {
public:
    // 1 - soldier
    // 0 - civilian
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        int m= mat.size();
        int n= mat[0].size();
        
        for(int i=m-1;i>=0;i--){
            int count=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            pq.push({count,i});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

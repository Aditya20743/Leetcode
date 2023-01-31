class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int soldierCount=0;
        priority_queue< pair<int,int> > maxh;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1)    soldierCount++;
            }
            maxh.push({soldierCount,i});
            soldierCount=0;
            if(maxh.size()>k)
                maxh.pop();
        }
        vector<int> ans(k);
        while(!maxh.empty()){
            ans[--k]=maxh.top().second;
            maxh.pop();
        }
        return ans;
    }
};
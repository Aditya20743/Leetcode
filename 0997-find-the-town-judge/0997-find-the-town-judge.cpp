class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int indeg[n+1];
        int outdeg[n+1];
        for(int i=0;i<=n;i++)    indeg[i]=0;
        for(int i=0;i<=n;i++)    outdeg[i]=0;
        
        for(int i=0;i<trust.size();i++){
            outdeg[trust[i][0]]++;
            indeg[trust[i][1]]++;
        }
        for(int i=1;i<n+1;i++){
            if(indeg[i]== n-1 && outdeg[i]== 0) return i;
        }
        return -1;
    }
};
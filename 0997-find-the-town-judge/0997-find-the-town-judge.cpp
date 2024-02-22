class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(n==1 && trust.size()==0)    return 1;
        
        unordered_map<int,int> indeg,outdeg;
        int tj=-1;
        for(auto it: trust){
            indeg[it[1]]++;
            outdeg[it[0]]++;
            if(indeg[it[1]]== n-1){
                tj= it[1];
            }
            
        }
        
        if(outdeg[tj]==0){
            return tj;
        }
        return -1;
        
    }
};
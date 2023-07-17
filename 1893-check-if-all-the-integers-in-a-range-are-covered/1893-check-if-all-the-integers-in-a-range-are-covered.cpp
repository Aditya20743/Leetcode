class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        unordered_map<int,int>  mp;
        for(auto it: ranges){
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int c=0;
        for(int i=0;i<left;i++){
            if(mp.find(i)!= mp.end())
                c+= mp[i];
        }
        
        for(int i=left;i<=right;i++){
            if(mp.find(i)!= mp.end())
                c+= mp[i];
            if(c==0) return false;
        }
        
        return true;
    }
};
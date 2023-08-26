class Solution {
    static bool cmp(vector<int>a, vector<int> b){
        return a[1]< b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        
        int start= pairs[0][0];
        int end= pairs[0][1];
        int count=1;
        
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]> end){
                count++;
                start = pairs[i][0];
                end = pairs[i][1];
            }
            // else{
            //     continue;
            // }
        }
        
        return count;
    }
};


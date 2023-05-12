class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        int n=interval.size();
        vector<vector<int>> ans;
        sort(interval.begin(),interval.end());
        
        int start= interval[0][0];
        int end= interval[0][1];
        for(int i=1;i<n;i++){
            if(interval[i][0] <= end){
                end= max(end,interval[i][1]);
            }
            else{
                ans.push_back({start,end});
                start= interval[i][0];
                end= interval[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
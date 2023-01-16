class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l=newInterval[0];
        int r=newInterval[1];
        int n=intervals.size();
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            if(intervals[i][0]>r){
                ans.push_back({l,r});
                l=intervals[i][0];
                r=intervals[i][1];
            }
            else if(intervals[i][1]<l){
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
            else {
                l= min(intervals[i][0],l);
                r= max(intervals[i][1],r);
            }
            // else{
            //     vector<int> temp;
            //     temp.push_back(l);
            //     temp.push_back(r);
            //     ans.push_back(temp);
            //     temp.clear();
            //     l=intervals[i][0]; r=intervals[i][1];
            // }
            
        }
        ans.push_back({l,r});
        return ans;
        
    }
};
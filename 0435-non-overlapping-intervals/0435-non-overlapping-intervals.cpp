class Solution {
public:
    static bool comp (vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),comp);
        
        int ans = 0, previous = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[previous][1]) {
                ans++;
                if (intervals[i][1] < intervals[previous][1]) previous = i;
            }
            else previous = i;
        }
        return ans;
    }
};
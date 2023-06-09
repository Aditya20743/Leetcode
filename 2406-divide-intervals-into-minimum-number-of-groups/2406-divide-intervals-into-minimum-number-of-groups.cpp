class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        // vector<vector<int>> allgroups;
        
        int n= intervals.size();
        
        vector<int> v(1e6+2,0);
        
        for(int i=0;i<n;i++){
            v[intervals[i][0]]+=1;
           
            v[intervals[i][1]+1]+=-1;
        }
        // for(int i=0;i<15;i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        
        int maxi=1;
        
        for(int i=1;i<1e6+2;i++){
            
            v[i]=v[i]+ v[i-1];
            
            maxi=max(maxi, v[i]);
        }
        return maxi;
    }
};
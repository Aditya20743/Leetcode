class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long,long long> > mh;
        
        for(int i=0;i<points.size();i++){
            long long dis= points[i][0]*points[i][0]+ points[i][1]*points[i][1];
            mh.push({dis, i});
            if(mh.size()>k){
                mh.pop();
            }
        }
        vector<vector<int>>ans;
        while(!mh.empty()){
            vector<int> p= points[mh.top().second];
            ans.push_back(p);
            mh.pop();
        }
        return ans;
    }
};
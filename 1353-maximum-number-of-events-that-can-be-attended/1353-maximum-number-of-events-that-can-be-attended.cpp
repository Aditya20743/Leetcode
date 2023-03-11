class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int> > pq;
        sort(events.begin(),events.end());
        int i=0, n= events.size(), maxi=0,count=0;
        for(auto it: events)    maxi= max(maxi,it[1]);
        
        for(int d=1;d<=maxi;d++){
            while(pq.size() && pq.top()<d){
                pq.pop();
            }
            while(i<n && events[i][0] == d){
                pq.push(events[i][1]);
                i++;
            }
            if(pq.size()){
                pq.pop();
                count++;
            }
        }
        return count;
    }
};
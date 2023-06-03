class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>> subordinates(n);
        
        for(int i=0;i<manager.size();i++){
            if(manager[i]!= -1){
                subordinates[manager[i]].push_back(i);
            }
        }
        
        queue<pair<int,int>> q;
        
        q.push({headID,0});
        
        int max_time=0;
        
        while(!q.empty()){
            int employee= q.front().first;
            int curr_time= q.front().second;
            
            q.pop();
            
            max_time= max(curr_time, max_time);
            
            for(auto subordinate: subordinates[employee]){
                q.push({subordinate, curr_time+ informTime[employee]});
            }
        }
        return max_time;
    }
};
class Solution {
public:
    //bool comp(int tasks1[0], int tasks1[0])
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](const auto &t1, const auto &t2){
            return t1[1] < t2[1];}
        );
        
        int computerOn[2001]={};
        
        for(auto it: tasks){
            int start= it[0], end= it[1], duration=it[2];
            for(int i=start;i<=end;i++){
                if(computerOn[i]){
                    duration--;
                }
            }
            for(int i=end; duration>0;i--){
                if(computerOn[i])   continue;
                if(duration){
                    computerOn[i]=1;
                    duration--;
                }
            }
        }
        int time=0;
        for(auto it:computerOn){
            time+= it;
        }
        return time;
    }
};
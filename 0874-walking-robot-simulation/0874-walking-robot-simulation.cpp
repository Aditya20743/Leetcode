class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for(auto it: obstacles){
            string key = to_string(it[0]) + '_' + to_string(it[1]);
            st.insert(key);
        }
        
        int x=0;
        int y=0;
        int maxD=0;
        
        
        pair<int,int> dir = {0,1};  // North
        
        for(int i=0;i<commands.size();i++){
            if(commands[i]== -1){
                dir = {dir.second, -dir.first};
            }
            else if(commands[i] == -2){
                dir = {-dir.second, dir.first};
            }
            else{
                for(int j=1;j<=commands[i];j++){
                    int newx = x + dir.first;
                    int newy = y + dir.second;
                    
                    string newkey = to_string(newx) + '_' + to_string(newy);
                    
                    if(st.find(newkey)!= st.end()){
                        break;
                    }
                    
                    x= newx;
                    y= newy;
                    maxD = max(maxD, x*x+ y*y);
                }
            }
        }
        return maxD;
    }
};
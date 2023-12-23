class Solution {
public:
    bool isPathCrossing(string path) {
        int dir[5]={-1,0,1,0,-1};
        int x=0,y=0;
        
        map<pair<int,int>,int> mp;
        mp[{0,0}]=1;
        
        for(int i=0;i<path.size();i++){
            if(mp[{x,y}]>1 ){
                // if((x==0 && y==0)){
                //     if(i!= path.size()-1){
                //         return true;
                //     }
                // }
                return true;
            }
            if(path[i]=='E'){
                x+= dir[0];
                y+= dir[1];
            }
            else if(path[i]=='W'){
                x+=dir[2];
                y+=dir[3];
            }
            else if(path[i]=='N'){
                x+=dir[3];
                y+=dir[4];
            }
            else{
                x+=dir[1];
                y+=dir[2];
            }
            mp[{x,y}]++; 
        }
        if(mp[{x,y}]>1 ){
                return true;
            }
        return false;
    }
};
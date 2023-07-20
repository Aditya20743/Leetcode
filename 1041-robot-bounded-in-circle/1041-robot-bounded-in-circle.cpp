class Solution {
public:
    // 0 - north
    // 1 - east
    // 2 - south
    // 3 - west
    bool isRobotBounded(string i) {
        int dir=0,x=0,y=0;
        int l=0,r=0;
        for(auto it: i){
            if(it=='L'){
                dir--;
                l++;
                dir =(4+dir)%4;
                // cout<<dir<<endl;
            }
            else if(it=='R'){
                dir++;
                r++;
                dir =(4+dir)%4;
                // cout<<dir<<endl;
            }
            else{
                dir =(4+dir)%4;
                if(dir==0)  y+=1;
                else if(dir==1) x+=1;
                else if(dir==2) { y-=1;}
                else if(dir==3) x-=1;
                // cout<<x<<" "<<y<<endl;
            }
            dir =(4+dir)%4;
        }
        // cout<<l<<" "<<r<<endl;
        if(x==0 && y==0)    return true;
        if(dir==0){
            return false;
        }
        return true;
    }
};
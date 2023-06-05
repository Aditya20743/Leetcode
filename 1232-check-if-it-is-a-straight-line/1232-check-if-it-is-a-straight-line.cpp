class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2)   return true;
        
        double x1= coordinates[0][0], x2= coordinates[1][0];
        double y1= coordinates[0][1], y2= coordinates[1][1];
        
        double m=  (y2-y1)/(x2-x1);
        
        if(x2-x1== 0){
            m= INT_MAX;
        }
        
        
        for(int i=2;i<coordinates.size();i++){
            double y=coordinates[i][1], x= coordinates[i][0];
            
            double m2= (y - y1)/ (x- x1);
            
            if(x-x1== 0){
            m2= INT_MAX;
        }
            
            if(m2!= m)  return false;
        }
        return true;
    }
};
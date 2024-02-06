class Solution {
public:
    static bool cmp(vector<int>v, vector<int>r){
        if(v[0]<r[0]){
            return true;
        }
        else if(v[0]>r[0]){
            return false;
        }
        return v[1]>r[1];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),cmp);
        
        int i=0, n=points.size();
        
        // int nxt=0;
        // int l1= points[0][1], l0= points[0][0];
        int c=0;
        
        
        for(i=0;i<n;i++){
            int y= INT_MIN;
            for(int j=i+1;j<n;j++){
                if( points[i][1] >= points[j][1] && y< points[j][1]){
                    c++;
                    y= points[j][1];
                }
            }
        }
        return c;
        
    }
};
class Solution {
public:
    // static bool cmp(vector<int>v, vector<int>r){
    //     if(v[0]<r[0]){
    //         return true;
    //     }
    //     else if(v[0]>r[0]){
    //         return false;
    //     }
    //     return v[1]>r[1];
    // }
    int numberOfPairs(vector<vector<int>>& points) {
        // sort(points.begin(), points.end());
        
        int i=0, n=points.size();
        
        // int nxt=0;
        // int l1= points[0][1], l0= points[0][0];
        int c=0;
        
        for(i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!= j && points[i][1] >= points[j][1] && points[i][0]<= points[j][0]){
                    bool tr = true;
                    for(int k=0;k<n ;k++){
                        if(k!=i && k!=j){
                            if(points[k][0]>= points[i][0] && points[k][0]<= points[j][0] 
                               && points[k][1]<= points[i][1] && points[k][1]>= points[j][1]){
                                tr= false;
                            }
                        }
                    }
                    if(tr==true){
                        c++;
                    }
                }
            }
        }
        return c;
        
    }
};
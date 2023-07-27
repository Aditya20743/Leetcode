class Solution {
public:
    bool check(int mid,vector<int>& dist, double hour ){
        double t=0;
        for(int i=0;i<dist.size()-1;i++){
            t+= ceil(1.0*dist[i]/mid);
            // if(mid==){
            //     cout<<t<<" ";
            // }
        }
        // cout<<mid<<endl;
        t+= 1.0*dist[dist.size()-1]/ mid;
        // cout<<t<<endl;
        return t<= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(dist.size() > ceil(hour)){
            return -1;
        }
        double l= 0, h= 1e9;
        int speed=-1;
        
        while(l<=h){
            int mid = l + (h-l)/2;
            
            bool t= check(mid, dist, hour);
            if(t){
                speed= mid;
                h=mid-1;
            }
            else{
                l= mid+1;
            }
        }
        return speed;
    }
};
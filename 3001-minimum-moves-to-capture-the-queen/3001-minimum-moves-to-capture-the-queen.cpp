class Solution {
public:
    
    
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        
        if(e==a ){
            if(c==a){
                if((b<d && d<f) || (b>d && d>f)){}
                else return 1;
            }
            else return 1;
        }
        
        if(b==f){
            if(d==f){
                if((a<c && c<e) || (a>c && c>e)){}
                else return 1;
            }
            else return 1;
        }
        
        int nc=c, nd=d;
        
        while(nc>=1 && nc<=8 && nd>=1 && nd<=8){
            if(nc==e && nd==f){
                return 1;
            }
            else if(nc==a && nd==b){
                break;
            }
            nc++;   nd++;
        }
        
        nc=c, nd=d;
        while(nc>=1 && nc<=8 && nd>=1 && nd<=8){
            if(nc==e && nd==f){
                return 1;
            }
            else if(nc==a && nd==b){
                break;
            }
            nc--;   nd--;
        }
        
        nc=c, nd=d;
        while(nc>=1 && nc<=8 && nd>=1 && nd<=8){
            if(nc==e && nd==f){
                return 1;
            }
            else if(nc==a && nd==b){
                break;
            }
            nc--;   nd++;
        }
        
        nc=c, nd=d;
        while(nc>=1 && nc<=8 && nd>=1 && nd<=8){
            if(nc==e && nd==f){
                return 1;
            }
            else if(nc==a && nd==b){
                break;
            }
            nc++;   nd--;
        }
        
        return 2;
    }
};
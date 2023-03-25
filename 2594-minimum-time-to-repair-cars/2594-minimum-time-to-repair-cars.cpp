class Solution {
public:
    
    bool check(long long mid,vector<int>&ranks, int cars){
         long long x=0;
        for(int i=0;i<ranks.size();i++){
            //long double t= ( mid)/(ranks[i]);
            x += (long long)sqrtl( (1.0* mid)/(ranks[i]));
        }
        if(x>= cars)    return true;
        return false;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        unsigned long long ul= 1e16, ll= 1;
        //sort(ranks.begin(),ranks.end());
        
        while(ul>= ll){
            long long mid= ll+(ul-ll)/2;
            
            if(check(mid,ranks,cars)){
                ul= mid-1;
            }
            else{
                ll= mid+1;
            }
        }
        return ul+1;
        
    }
};
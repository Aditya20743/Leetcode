class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0;
        int gv=0,mv=0,pv=0;
        
        for(int i=1;i<travel.size();i++){
            travel[i]+= travel[i-1];
        }
        
        vector<int> mtrv;
        mtrv.push_back(0);
        for(auto it: travel){
            mtrv.push_back(it);
        }
        
        for(int i=0;i<garbage.size();i++){
            for(auto it: garbage[i]){
                if(it=='G'){
                    ans+= mtrv[i]- mtrv[gv];
                    gv= i;
                    ans+= 1;
                }
                else if(it=='P'){
                    ans+= mtrv[i] - mtrv[pv];
                    pv= i;
                    ans+=1;
                }
                else if(it=='M'){
                    ans+= mtrv[i] - mtrv[mv];
                    mv= i;
                    ans+=1;
                }
            }
        }
        return ans;
    }
};
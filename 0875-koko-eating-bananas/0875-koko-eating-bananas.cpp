class Solution {
public:
    bool check(int mid, vector<int>&piles, int h){
        long long t=0;
        for(int i=0;i<piles.size();i++){
            double it= piles[i];
            t+= ceil(it/mid);
        }
        if(t<= h)   return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long ul= *max_element(piles.begin(),piles.end()), ll= 1;
        long long mid=0;
        int ans=0;
        while(ul>= ll){
            mid= ll+ (ul-ll)/2;
            
            if(check(mid,piles,h)){
                ul = mid-1;
                ans= mid;
            }
            else{
                ll= mid+1;
            }
        }
        return ans;
    }
};
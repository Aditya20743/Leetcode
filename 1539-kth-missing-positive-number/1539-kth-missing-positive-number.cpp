class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxi= *max_element(arr.begin(),arr.end());
        int j=0;
        for(int i=1;i<=maxi;i++){
            if(arr[j]==i){
                j++;
            }
            else{
                k--;
                if(k==0)    return i;
                // j++;
            }
        }
        if(k==0)    return maxi+1;
        while(k--){
            maxi++;
        }
        return maxi;
    }
};
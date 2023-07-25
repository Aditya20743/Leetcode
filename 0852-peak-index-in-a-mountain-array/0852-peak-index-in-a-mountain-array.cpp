class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        
        while(l<r){
            int m= l+(r-l)/2;
            if(arr[m]> arr[m+1] && arr[m]> arr[m-1]){
                return m;
            }
            else if(arr[m-1]< arr[m]){
                l= m;
            }
            else if(arr[m]> arr[m+1]){
                r = m;
            }
        }
        return -1;
    }
};
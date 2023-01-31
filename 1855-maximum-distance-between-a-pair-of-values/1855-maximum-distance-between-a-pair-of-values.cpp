class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        int maxi=0;
        while(i< nums1.size() && j< nums2.size()){
            if(i<=j && nums1[i]<=nums2[j]){
                maxi=max(maxi,j-i);
                j++;
            }
            else if(i>j){
                j++;
            }
            else{
                i++;
            }
        }
        return maxi;
    }
};
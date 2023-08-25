class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        
        for(auto it: nums2){
            nums1.push_back(it);
        }
        sort(nums1.begin(),nums1.end());
        
        if(nums1.size()%2==1){
            return nums1[nums1.size()/2];
        }
        return (1.0*nums1[nums1.size()/2-1] + 1.0*nums1[nums1.size()/2 ])/2;
        
    }
};
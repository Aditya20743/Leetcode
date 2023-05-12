class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        vector<int> nums= nums1;
        nums1.clear();
        while(i<m && j<n){
            if(nums[i]<nums2[j]){
                nums1.push_back(nums[i]);
                i++;
            }
            else{
                nums1.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            nums1.push_back(nums[i++]);
        }
        while(j<n){
            nums1.push_back(nums2[j++]);
        }
    
    }
};

class Solution {
public:
    int helper(vector<int> nums1, vector<int> nums2, int m1, int m2){
        int c=0;
        for(int i=0;i<nums1.size()-1;i++){
            if(nums1[i]> m1 && nums2[i]<=m1 && nums1[i]<= m2){
                c++;
            }
            else if(nums1[i]> m1 && (nums1[i]>m2 || nums2[i]>m1)){
                return -1;
            }
        }
        
        for(int i=0;i<nums1.size()-1;i++){
            if(nums2[i]> m2 && nums1[i]<=m2 && nums2[i]<= m1){
                c++;
            }
            else if(nums2[i]> m2 && (nums2[i]>m1 || nums1[i]>m2) ){
                return -1;
            }
        }
        return c;
    }
    
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size(), m1= -1, m2=-1;
        
        
        int l1= helper(nums1, nums2, nums1[n-1], nums2[n-1]);
        
        swap(nums1[n-1], nums2[n-1]);
        int l2= helper(nums1, nums2, nums1[n-1], nums2[n-1]);
        
        if(l1== -1){
            l1 =1e9;
        }
        if(l2== -1){
            l2= 1e9;
        }
        
        if(l1 == 1e9 && l2==1e9)    return -1;
        
        return min(l1,l2+1);
    }
};
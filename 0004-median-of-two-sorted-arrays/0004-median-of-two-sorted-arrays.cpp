class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        int idx=-1, idx2= -1;
        
        if((n+m)%2==1 ){
            idx = (n+m)/2;
        }
        else{
            idx = (n+m)/2 -1;
            idx2= (n+m)/2;
        }
        double ans1=0 , ans2=0;
        int i=0,j=0;
        while(idx>=0){
            if(i<n && j<m && nums1[i]> nums2[j]){
                ans1=nums2[j];
                j++;
                idx--;
            }
            else if(i<n && j<m && nums1[i]<= nums2[j]){
                ans1= nums1[i];
                i++;
                idx--;
            }
            else if(i==n){
                ans1 = nums2[j];
                j++;
                idx--;
            }
            else if(j==m){
                ans1= nums1[i];
                i++;
                idx--;
            }
        }
        
        if(idx2==-1){
            return ans1;
        }
        else{
            if(i<n && j<m && nums1[i]> nums2[j]){
                ans2=nums2[j];
            }
            else if(i<n && j<m && nums1[i]<= nums2[j]){
                ans2= nums1[i];
            }
            else if(i==n){
                ans2 = nums2[j];
            }
            else if(j==m){
                ans2= nums1[i];
            }
            
            // if(nums1[i]>nums2[j])   ans2 =nums2[j];
            // else ans2= nums1[i];
            
        }
        
        return (ans1 + ans2)/2;
        
//         for(auto it: nums2){
//             nums1.push_back(it);
//         }
//         sort(nums1.begin(),nums1.end());
        
//         if(nums1.size()%2==1){
//             return nums1[nums1.size()/2];
//         }
//         return (1.0*nums1[nums1.size()/2-1] + 1.0*nums1[nums1.size()/2 ])/2;
        
    }
};
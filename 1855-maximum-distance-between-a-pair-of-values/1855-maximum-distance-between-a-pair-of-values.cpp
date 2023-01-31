class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int maxi=0;
        
        for(int i=0;i<nums1.size();i++){
            auto lower= lower_bound(nums2.rbegin(),nums2.rend(),nums1[i])- nums2.rbegin();
            int idx= nums2.size()-lower-i-1;
            maxi=max(maxi,idx); 
            cout<<idx<<" ";
        }
        cout<<endl;
        return maxi;
    }
};
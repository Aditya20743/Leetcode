#define ll long long
class Solution {
public:    
    ll count(vector<int>&nums, int l, int m, int r){
        ll res=0;
        int t1=0, t2=m+1;
        
        for (t1 = l; t1 <= m; t1++) {
            while (t2 <= r && 1LL*nums[t1] > 2LL * nums[t2]) t2++;
            res += (t2-(m+1));
        }
        return res;
    }
    
    void merge(vector<int>&nums, int l, int m, int r){
        vector<int> temp;
        
        int t1= l, t2= m+1;
        
        while(t1<=m && t2<= r){
            if(nums[t1]< nums[t2]){
                temp.push_back(nums[t1]);
                t1++;
            }
            else{
                temp.push_back(nums[t2]);
                t2++;
            }
        }
        while(t1<=m){
            temp.push_back(nums[t1]);
            t1++;
        }
        while(t2<=r){
            temp.push_back(nums[t2]);
            t2++;
        }
        
        for(int i=l;i<=r;i++){
            nums[i] = temp[i-l];
        }
        
    }
    
    int mergeSort(vector<int>&nums, int l, int r){
        ll ans=0;
        
        if(l==r)    return 0;
        
        int m= l+ (r-l)/2;
        
        ans+= mergeSort(nums, l, m);
        ans+= mergeSort(nums, m+1, r);
        
        ans+= count(nums, l, m, r);
        merge(nums, l, m, r);
        
        return ans;
    }
    
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};
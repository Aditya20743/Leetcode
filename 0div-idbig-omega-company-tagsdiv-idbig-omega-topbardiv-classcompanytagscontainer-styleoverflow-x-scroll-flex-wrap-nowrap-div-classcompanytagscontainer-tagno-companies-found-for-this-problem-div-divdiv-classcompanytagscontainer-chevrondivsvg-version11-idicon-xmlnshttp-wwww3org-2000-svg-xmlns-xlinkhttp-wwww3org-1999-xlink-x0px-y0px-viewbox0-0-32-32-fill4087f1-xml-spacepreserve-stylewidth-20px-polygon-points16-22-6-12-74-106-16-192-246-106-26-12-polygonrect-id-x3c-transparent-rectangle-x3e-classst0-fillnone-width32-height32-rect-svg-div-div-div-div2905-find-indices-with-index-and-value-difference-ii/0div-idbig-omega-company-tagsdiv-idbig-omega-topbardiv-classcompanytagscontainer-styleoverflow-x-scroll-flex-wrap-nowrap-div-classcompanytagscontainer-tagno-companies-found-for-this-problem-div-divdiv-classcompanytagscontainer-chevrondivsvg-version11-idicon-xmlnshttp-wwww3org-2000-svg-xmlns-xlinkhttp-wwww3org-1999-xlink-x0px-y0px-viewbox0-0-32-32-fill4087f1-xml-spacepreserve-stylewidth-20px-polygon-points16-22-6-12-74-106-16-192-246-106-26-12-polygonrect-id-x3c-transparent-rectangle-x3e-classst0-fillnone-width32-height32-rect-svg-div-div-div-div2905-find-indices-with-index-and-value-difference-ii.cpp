class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        
        vector<int> v(2);
        
        vector<pair<int,int>> miniv(nums.size()), maxiv(nums.size());
        
        int jmin=-1, jmax= -1;
        int mini=INT_MAX; int maxi=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini){
                jmin = i;
                mini = nums[i];
            }
            miniv[i] ={mini, jmin};
            
            if(maxi<nums[i]){
                jmax = i;
                maxi = nums[i];
            }
            maxiv[i] ={maxi, jmax};
            
        }
        
        
        for(int i=indexDifference;i<nums.size();i++){
            jmin=miniv[i-indexDifference].second, mini= miniv[i-indexDifference].first;
            jmax=maxiv[i-indexDifference].second, maxi= maxiv[i-indexDifference].first;
            
            if(abs(nums[jmin] - nums[i])>= valueDifference ){
                v[0]= jmin;
                v[1]= i;
                return v;
            }
            else if(abs(nums[jmax] - nums[i])>= valueDifference ){
                v[0]= jmax;
                v[1]= i;
                return v;
            }
            
        }
        v[0]=-1;
        v[1]=-1;
        return v;
    }
};
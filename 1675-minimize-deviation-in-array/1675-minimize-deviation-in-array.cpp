class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<long long> s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)
                s.insert(nums[i]);
            else 
                s.insert(nums[i]*2);
        }
        long long mn=INT_MAX,mx=INT_MIN;
        long long dif= *s.rbegin()- *s.begin();
        
        while(*s.rbegin() %2==0){
            long long x= *s.rbegin();
            s.erase(x);
            s.insert(x/2);
            dif= min(dif, *s.rbegin()- *s.begin());
            
        }
        
        return dif;
    }
};
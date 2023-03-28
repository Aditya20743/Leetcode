class Solution {
public: 
    bool isPrime(int n)
    {
        
        if (n <= 1)
            return false;
      
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    

    bool primeSubOperation(vector<int>& nums) {
        int lastno=0;
        vector<int> copy(nums.size(),0);
        // while(copy!= nums){
        //     copy= nums;
            for(int i=0;i<nums.size();i++){
                int diff= nums[i]- lastno;
                //if(diff<=0) return false;

                for(int j=nums[i]-1;j>0;j--){
                    //diff= nums[i]- j;
                    if(isPrime(j) && nums[i]- j > lastno){
                        nums[i]= nums[i]-j;
                        lastno= nums[i];
                        break;
                    }
                }
                lastno= nums[i];
            }
            
        //}
        
        for(auto it: nums) cout<<it<<" ";
        cout<<endl;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                return false;
            }
        }
        return true;
    }
};
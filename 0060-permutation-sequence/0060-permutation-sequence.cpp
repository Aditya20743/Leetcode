class Solution {
public:
    string getPermutation(int n, int k) {
        // built in function
//         string first= "";
//         for(int i=0;i<n;i++){
//             first+= i+'1';
//         }
//         // cout<<first<<endl;
        
//         while(--k)
//         next_permutation(first.begin(), first.end());
        
//         return first;
        
        vector<int> nums;
        int fact=1;
        for(int i=1;i<n;i++){
            fact= fact*i;
            nums.push_back(i);
        }
        
        nums.push_back(n);
        
        // logic -> 0 based indexing
        k = k-1;
        
        string ans="";
        
        while(true){
            ans+= to_string(nums[k/fact]);
            // k/fact -> index of no of permutation
            
            nums.erase(nums.begin() + k/fact);
            // delete that no.
            
            if(nums.size()==0){
                break;
                // nums.size()=0 ==> all numbers used for permutation 
            }
            
            k= k % fact;
            // after each number selected for permutation,
            // k will be remaining of k/fact ;
            
            fact = fact / nums.size();
            // no will be reduced by one so possible permutation will be reduced 
        }
        return ans;
    }
};
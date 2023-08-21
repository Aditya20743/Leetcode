class Solution {
public:
    string getPermutation(int n, int k) {
        string first= "";
        for(int i=0;i<n;i++){
            first+= i+'1';
        }
        // cout<<first<<endl;
        
        while(--k)
        next_permutation(first.begin(), first.end());
        
        return first;
    }
};
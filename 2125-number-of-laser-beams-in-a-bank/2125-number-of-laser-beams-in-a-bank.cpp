class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m= bank.size();
        int n= bank[0].size();
        
        int last_count=0;
        int curr_count=0;
        int ans=0;
        
        for(int i=0;i<m;i++){
            curr_count=0;
            for(int j=0;j<n;j++){
                if(bank[i][j] == '1'){
                    curr_count++;
                }
            }
            if(curr_count!= 0){
                ans += last_count*curr_count;
                last_count= curr_count;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum=0;
        vector<int> ans;
        for(auto it: rolls){
            sum+= it;
        }
        
        int reqSum = (m+n)*(mean);
        
        int remSum = reqSum - sum;
        
        // out of range
        if(remSum > 6*n || remSum < 1*n){
            return {};
        }
        
        while(remSum){
            int num;
            if(remSum%n!=0){
                num =  remSum/n + 1;
            }
            else{
                num = remSum/n;
            }
            ans.push_back(num);
            remSum -= num;
            n--;
        }
        return ans;
    }
};
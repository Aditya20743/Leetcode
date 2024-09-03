class Solution {
private:
    int digitSum(int currSum){
        int newSum=0;
        while(currSum){
            newSum+= currSum%10;
            currSum/= 10;
        }
        return newSum;
    }
    
public:
    int getLucky(string s, int k) {
        int currSum=0;
        for(auto it: s){
            int num = it-'a'+1;
            if(num>=10){
                currSum+= num%10;
                num/= 10;
                currSum+= num%10;
            }
            else
                currSum += it-'a'+1;
        }
        cout<<currSum<<endl;
        while(--k){
            currSum = digitSum(currSum);
            cout<<currSum<<endl;
        }
        return currSum;
    }
};
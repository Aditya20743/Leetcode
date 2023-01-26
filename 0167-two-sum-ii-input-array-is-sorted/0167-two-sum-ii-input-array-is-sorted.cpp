class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l =0, r= numbers.size()-1;
        while(l<r){
            //int m=l+(r-l)/2;
            if(numbers[l]+ numbers[r]== target){
                return {l+1,r+1};
            }
            else if(numbers[l]+numbers[r]> target)  r--;
            else    l++;
        }
        return {-1,-1};
    }
};
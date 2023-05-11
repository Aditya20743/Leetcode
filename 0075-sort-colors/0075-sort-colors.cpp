class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0, h=nums.size()-1, i=0;
        while(i<=h){
            
            switch (nums[i]){
                case 0:
                    swap(nums[l],nums[i]);
                    l++;
                    i++;
                    break;
                case 1:
                    i++;
                    break;
                case 2: 
                    swap(nums[h],nums[i]);
                    h--;
                    break;
            }
        }
        //return nums;
    }
};
/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    let data = [];
    for(let i=0;i<nums.length;i++){
        if(data[nums[i]]== undefined){
            data[nums[i]] = 1;
        }
        else{
            return nums[i];
        }
    }
};
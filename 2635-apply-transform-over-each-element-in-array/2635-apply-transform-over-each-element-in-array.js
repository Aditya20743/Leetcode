/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const returnedArray =[];
    
    arr.forEach((ele, index)=>{
        returnedArray[index] = fn(arr[index], index);
    })
    
    // for(let i=0;i<arr.length;i++){
    //     returnedArray[i] = fn(arr[i],i);
    // }

    
    // does not work -> const returndArray = arr.forEach(fn);
    // const returnedArray = arr.map(fn);
    return returnedArray;
};
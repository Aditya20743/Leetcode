/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const filteredArr =[];
    
    let i=0;
    arr.map((ele, index)=>{
        if(Boolean(fn(ele,index))===true){
            filteredArr[i++] =  ele;
        }
    });
    return filteredArr;
};
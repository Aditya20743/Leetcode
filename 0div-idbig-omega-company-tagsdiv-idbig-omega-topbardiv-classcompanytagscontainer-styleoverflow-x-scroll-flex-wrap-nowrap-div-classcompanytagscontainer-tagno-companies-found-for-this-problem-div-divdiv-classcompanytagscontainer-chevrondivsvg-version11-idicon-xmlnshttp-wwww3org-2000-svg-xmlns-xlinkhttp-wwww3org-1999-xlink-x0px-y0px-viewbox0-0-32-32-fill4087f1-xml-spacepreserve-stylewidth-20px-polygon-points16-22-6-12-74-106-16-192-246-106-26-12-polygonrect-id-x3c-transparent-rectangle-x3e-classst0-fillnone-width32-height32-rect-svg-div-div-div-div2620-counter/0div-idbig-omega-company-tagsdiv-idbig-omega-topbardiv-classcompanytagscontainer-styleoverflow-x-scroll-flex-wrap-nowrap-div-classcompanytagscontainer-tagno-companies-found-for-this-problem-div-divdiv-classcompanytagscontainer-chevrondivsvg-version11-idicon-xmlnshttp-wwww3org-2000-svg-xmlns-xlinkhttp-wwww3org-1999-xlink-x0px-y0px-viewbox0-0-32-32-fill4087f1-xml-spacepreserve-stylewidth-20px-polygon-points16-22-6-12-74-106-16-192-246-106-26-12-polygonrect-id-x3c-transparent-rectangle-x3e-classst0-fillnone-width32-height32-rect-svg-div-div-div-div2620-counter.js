/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let t=0;
    return function() {
        return n+(t++);
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
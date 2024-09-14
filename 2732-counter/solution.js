/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    var counter = 0;
    return function() {
        var ans = n + counter;
        counter++;
        return ans;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */

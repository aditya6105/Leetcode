/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    let c = 0;
    for(let i=0;i<args.length;i++) c++;
    return c;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */
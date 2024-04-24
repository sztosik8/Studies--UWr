var fib = function (n) {
    if (n < 2)
        return n;
    return fib(n - 1) + fib(n - 2);
};
function memoize(fn) {
    var cache = new Map();
    return function (n) {
        if (cache.has(n)) {
            return cache.get(n);
        }
        else {
            var result = fn(n);
            cache.set(n, result);
            return result;
        }
    };
}
fib = memoize(fib);
for (var i = 0; i < 50; i++) {
    console.log(fib(i));
}

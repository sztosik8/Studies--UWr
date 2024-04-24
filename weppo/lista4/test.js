function f(s) {
    if (s == "bar") {
        f = function (s) {
            return s + " zmienione";
        }
    }
    return s + " przed zmianą";
}
console.log(f('foo'));
console.log(f('bar'))
console.log(f('qux'));
console.log(f('foo'));
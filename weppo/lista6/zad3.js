function map(f, list) {
    for (var i = 0; i < list.length; i++) {
        list[i] = f(list[i]);
    }
    return list;
}
function filter(f, list) {
    var result = [];
    for (var i = 0; i < list.length; i++) {
        if (f(list[i])) {
            result.push(list[i]);
        }
    }
    return result;
}
function forEach(f, list) {
    for (var i = 0; i < list.length; i++) {
        f(list[i]);
    }
}
//testy
var list = [1, 2, 3, 4, 5];
console.log(map(function (x) { return x * x; }, list));
console.log(filter(function (x) { return x % 2 == 0; }, list));
forEach(function (x) { return console.log(x); }, list);

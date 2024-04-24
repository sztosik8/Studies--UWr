
function add(...args) {
    return args.reduce((accumulator, current) => accumulator + current, 0)
}
console.log(add(1, 2, 3, 4, 5));
// 15
console.log(add(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
// 55
console.log(add(1, 2));
// 3
console.log(add());
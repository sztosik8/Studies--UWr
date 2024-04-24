var arr = Array(1001).fill(0)
var prim = []

for (let i = 2; i < 1000000; i++) {
    if (arr[i] == 0) {
        prim.push(i);
    }
    for (let j = 2; i * j <= 1000; j++) {
        arr[i * j]++;
    }
}
console.log(prim)
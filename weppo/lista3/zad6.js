function fibiter() {
    var a = 0, b = 1;
    return {
        next: function () {
            [a, b] = [b, a + b];
            return {
                value: a,
                done: false,
            }
        }
    }
}

function* fibgen() {
    var a = 0, b = 1;
    while (true) {
        [a, b] = [b, a + b];
        yield a;
    }
}

var it = fibiter();

for (var res; res = it.next(), !res.done;) {
    console.log(res.value);
}

///  zad7

function* take(it, n) {
    for (let i = 0; i < n; i++) {
        yield it.next().value;
    }
}

for (let i of take(fibgen(), 10)) {
    console.log(i);
}
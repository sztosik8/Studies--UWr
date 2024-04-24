
function fib_iter(n) {
    var prev = 0, pres = 1

    while (n > 0) {
        var newN = (prev + pres);
        prev = pres;
        pres = newN;
        n--;
    }
    return pres;
}

function fib_rek(n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    else {
        return fib_rek(n - 1) + fib_rek(n - 2);
    }
}

for (let i = 10; i < 40; i++) {
    // console.log(fib_rek(i), fib_iter(i))
}

//console.log("czas dla funkcji rekurencyjnej");
for (let i = 30; i < 40; i++) {
    console.time();
    fib_rek(i);
    console.timeEnd();

    console.time();
    fib_iter(i);
    console.timeEnd();
}


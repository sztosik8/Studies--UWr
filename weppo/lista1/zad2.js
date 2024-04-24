var ans = []

function cond(n) {
    var sub = n;
    var sum_of_dig = 0;
    while (sub > 0) {
        var dig = sub % 10;

        if (dig == 0) { return false }


        if (n % dig == 0) { sum_of_dig += dig }
        else return false

        sub = (Math.floor(sub / 10));

    }

    if ((n % sum_of_dig) == 0) 
    {
        return true;
    }
    else return false;

}

for (let i = 1; i <= 1000000; i++) {
    if (cond(i)) {
        ans.push(i)
    }
}
console.log(ans)
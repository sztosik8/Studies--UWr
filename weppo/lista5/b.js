// b.js
module.exports = b ;

var a = require('./a');
function b(n) {
    if (n > 0) {
        console.log(n);
        a(n - 1);
    }
}
// a.js
module.exports = a ;

var b = require('./b');
function a(n) {
    if (n > 0) {
        console.log(n);
        b(n - 1);
    }
}
const fs = require('fs');
fs.readFile('/Users/sztosik/Documents/studia/weppo/lista5/text.txt', 'utf8', (err, data) => {
    if (err) throw err;
    console.log(data);
});
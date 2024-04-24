function hasProperty(obj, propName) {
    // Sprawdź, czy składowa występuje bezpośrednio w obiekcie
    return obj.hasOwnProperty(propName);
}

function enumerateProperties(obj) {
    let props = [];
    for (let prop in obj) {
        props.push(prop);
    }
    return props;
}

function enumerateOwnProperties(obj) {
    let props = [];
    for (let prop in obj) {
        if(hasProperty(obj, prop))props.push(prop);
    }
    return props;
}


var p = {
    name: 'jan'
}
var q = {
    surname: 'kowalski'
}

Object.setPrototypeOf(p, q);
console.log(p.name);
console.log(p.surname);

console.log(hasProperty(p, 'name')); // true
console.log(hasProperty(p, 'surname')); // false

console.log(enumerateOwnProperties(p)); // ['name']
console.log(enumerateProperties(p)); // ['name', 'surname']


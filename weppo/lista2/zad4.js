typeof 42; // "number"
typeof "hello"; // "string"
typeof true; // "boolean"
typeof {} // "object"
typeof [] // "object"
typeof function () { } // "function"

//Operator typeof służy do określenia typu danych wartości lub wyrażenia

class Person { }
const person = new Person();
console.log(person instanceof Person); // true

function Car() { }
const car = new Car();
console.log(car instanceof Car); // truej

// Operator instanceof służy do sprawdzania, czy dany obiekt jest instancją 
// (lub dziedziczy z) konkretnej klasy lub konstruktora


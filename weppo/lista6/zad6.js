"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.logPerson = exports.isUser = exports.isAdmin = exports.persons = void 0;
exports.persons = [
    {
        name: 'Jan Kowalski',
        age: 17,
        occupation: 'Student',
        type: 'user'
    },
    {
        name: 'Tomasz Malinowski',
        age: 20,
        role: 'Administrator',
        type: 'admin'
    }
];
function isAdmin(person) {
    return person.type === "admin";
}
exports.isAdmin = isAdmin;
function isUser(person) {
    return person.type === "user";
}
exports.isUser = isUser;
function logPerson(person) {
    var additionalInformation = '';
    if (isAdmin(person)) {
        additionalInformation = person.role;
    }
    if (isUser(person)) {
        additionalInformation = person.occupation;
    }
    console.log(" - ".concat(person.name, ", ").concat(person.age, ", ").concat(additionalInformation));
}
exports.logPerson = logPerson;
logPerson(exports.persons[0]);
logPerson(exports.persons[1]);

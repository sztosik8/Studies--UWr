
n = Math.floor(Math.random() * 101)
const stdin = process.stdin;
process.stdout.write('Zgadnij liczbę\n');


stdin.addListener('data', (num) => {

    if (num === n) {
        console.log(`To jest właśnie ta liczba`);
        stdin.pause();
    }
    if (num > n) {
        console.log(`moja liczba jest mniejsza`)
    }
    else if (num < n) {
        console.log(`moja liczba jest wieksza`)
    }
});



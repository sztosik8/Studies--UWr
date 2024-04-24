# Katarzy Trzos
# Lista 4
# Zadanie 1

import timeit


def pierwsze_imperatywna(n):
    sito = [0] * n
    prime = []
    for i in range(2, n):
        if sito[i] == 0:
            prime.append(i)
            j = 2
            while (i*j < n):
                sito[i*j] = 1
                j += 1

    return prime


def is_prime(x):
    if x <= 1:
        return False
    for i in range(2, x):
        if x % i == 0:
            return False
    return True


def pierwsze_skladana(n):
    nums = range(2, n)
    prime = [num for num in nums if is_prime(num)]
    return prime


def pierwsze_funkcyjna(n):
    nums = range(2, n)
    prime = list(filter(lambda x: is_prime(x), nums))
    return prime


def measureFunction(func, n):
    start = timeit.default_timer()
    func(n)
    end = timeit.default_timer()
    return end - start


def makeTable():
    print('{:<5} {:<15} {:<15} {:<15}'.format(
        'n', 'Imperatywna', 'Skladana', 'Funkcyjna'))
    for i in range(0, 101, 10):
        print('{:<5} {:<15} {:<15} {:<15}'.format(i, round(measureFunction(pierwsze_imperatywna, i), 6), round(
            measureFunction(pierwsze_skladana, i), 6), round(measureFunction(pierwsze_funkcyjna, i), 6)))


makeTable()

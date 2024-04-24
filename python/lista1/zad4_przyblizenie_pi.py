# Katarzyna Trzos
# Lista 1
# Zadanie 4

import math
import random

# rozmiar kwadratowej planszy ma 2*size x 2*size
# ramie okregu R = size
size = 1000
# liczba losowan
los = 5000
# blad zaokreaglenia wyniku
blad = 0.01


def in_circle(x, y, size):
    # sprawdzamy czy dany punkt znajduje sie w okregu
    # (czy odleglosc puntu jest mniejsza rowna R okregu)
    if (x * x + y * y <= size * size):
        return True
    else:
        return False


def approx_pi(throws_max, blad):
    throws_curr = 0
    ltwo = 0

    while (throws_curr <= throws_max):

        x = random.randint(-size, size)
        y = random.randint(-size, size)

        throws_curr += 1

        if (in_circle(x, y, size)):
            ltwo += 1

        p = (4 * ltwo)/throws_curr
        print(p)

        if (abs(p - math.pi) < blad):
            break


approx_pi(los, blad)  # (liczba losowan, blad przyblizenia)

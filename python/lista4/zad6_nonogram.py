# Katarzy Trzos
# Lista 4
# Zadanie 5

def check(tab, v):
    n = len(tab)
    m = len(tab[0])
    for i in range(n):
        shadow = 0
        for j in range(m):
            if tab[i][j] == 1:
                shadow += 1
        if (shadow != v[i]):
            return False
    return True


def wypisz(tab):
    matr = (
        '\n'.join([''.join(['# ' if val == 1 else '- ' for val in row]) for row in tab]))
    return matr


def next_b(b, H, n):
    m = len(b)
    for i in range(m-1, -1, -1):
        if b[i] + H[i] + 1 > n:
            b[i] = 0
        else:
            b[i] += 1
            return b
    return []


def shadow(H, V):

    n = len(V)
    m = len(H)

    # tablica wypelniona zerami
    matrix = [[0 for j in range(m)] for i in range(n)]

    # lista trzymajaca informacje od ktorego wiersza bedziemy cieniowac w danej kolumnie
    # w pierwszym kroku cieniujemy wszytkie kolumny zaczynajac od 0-wych wierszy
    col = [0 for i in range(m)]

    while col != []:
        # cieniujemy komorki w tablicy matrix zaczynajac od wiersza zapisanego w liscie col
        for i in range(m):
            for j in range(H[i]):
                matrix[j + col[i]][i] = 1

        # sprawdzamy czy cieniowanie sie zgadza z cieniowaniem wektore V
        if check(matrix, V):
            yield (wypisz(matrix))

        matrix = [[0 for j in range(m)] for i in range(n)]

        # wyznaczamy kolejna mozliwosc cieniowania
        col = next_b(col, H, n)


H = (2, 1, 3, 1)
V = (1, 3, 1, 2)

rozwiazania = shadow(H, V)
for i in rozwiazania:
    print(i)
    print('\n')

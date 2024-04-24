# Katarzna Trzos
# Lista 3
# Zadnaie 5

def max_sublist_sum(a):

    max_overal = float('-inf')
    new_max = 0
    start = 0
    end = 0
    s_new = 0

    for i in range(0, len(a)):

        new_max += a[i]

        if max_overal < new_max:
            max_overal = new_max
            start = s_new
            end = i

        if new_max < 0:
            new_max = 0
            s_new = i+1

    print("najwieksza podsuma zanjduje sie miedzy indeksami:", [start, end])


a = [-2, -3, 4, -1, -2, 1, 5, -3]
b = [1, 5, -96, 14, -9, 17, -39, 3]

max_sublist_sum(a)
max_sublist_sum(b)

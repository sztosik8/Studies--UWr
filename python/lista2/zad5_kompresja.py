# Katarzna Trzos
# Lista 2
# Zadnaie 5

# funkcja liczy wystapienie znaku word[i] w slowie word o dlugosci len
def num_of_lett(i, word, len):
    how_many = 1

    while (i < len-1):
        if (word[i] == word[i+1]):
            how_many += 1
        else:
            break
        i += 1

    return how_many


def kompresja(text):
    while True:

        # wczytaj jedna linijke
        file_line = text.readline()

        if not file_line:
            break

        # podziel linijke na slowa(wyrazy oddzielone spacjami)
        for word in file_line.split():
            output_ko.write("[")
            length = len(word)
            i = 0
            while (i < length):
                # policz ile razy nastepuje wystapienie litery
                j = num_of_lett(i, word, length)

                # stworz pare skladajaca sie z liczby wystapien i znaku
                pair = (j, word[i])

                # wpisz pare do pliku wyjsciowego
                output_ko.write(
                    (str(pair)))
                i += j

                # jesli nie jestes na ostatniej literze to oddziel kolejne wyjscie przecinkiem
                if (i < length):
                    output_ko.write(", ")

            # koniec slowa
            output_ko.write("]")

        # koniec lini
        output_ko.write("\n")


# funkcja zwraca liczbe i znak z wyrazen postaci: [(n, 'a'); (n, 'a'); (1, '.')]
def get_num_and_lett(str):
    num = ""
    i = 0
    while (not (str[i].isdigit())):
        i += 1
    while str[i] != ",":
        num += str[i]
        i += 1
    while str[i] != "'":
        i += 1
    lett = str[i+1]

    return int(num), lett


def dekompresja(text):
    while True:

        file_line = text.readline()

        # podziel wczytana linie na "slowa", czyli wyrazy ktore beda oddzielone spacja
        words_ko = file_line.split("][")

        if not file_line:
            break

        for word in words_ko:

            # podziel slowo na krotki postaci: [(n, 'a'); (n, 'a'); (1, '.')]
            trups = word.split("), (")
            for pair in trups:

                # wyjmij z krotki znak i ilosc jego powtorzen i wypisz do pliku
                n, lett = get_num_and_lett(pair)

                for i in range(n):
                    output_de.write(lett)

            output_de.write(" ")    # slowa oddziel spacja

        output_de.write("\n")       # nowe linie oddziel enterem

# -------MAIN-------


input_ko = open("myfile.txt", "r+")
output_ko = open("out_ko.txt", "w")


kompresja(input_ko)

input_ko.close()
output_ko.close()

input_de = open("out_ko.txt", "r+")
output_de = open("out_de.txt", "w")

dekompresja(input_de)


input_de.close()
output_de.close()

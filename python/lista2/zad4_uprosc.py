# Katarzna Trzos
# Lista 2
# Zadnaie 4
import random

# http://www.weimarer-dreieck.eu/fileadmin/templates/multiflex3/PDF/Pan_Tadeusz-_PL.pdf




def usun_dlugie(words, dl_slowa):
    new_text = []
    for word in words:
        if (len(word) <= dl_slowa):
            new_text.append(word)
    return new_text


def usun_losowe(words, liczba_slow):
    list = [i for i in range(0, len(words))]
    index = random.sample(list, liczba_slow)
    index.sort()
    new_text = []
    for i in index:
        new_text.append(words[i])
    return new_text


def uprosc_zdanie(text, dl_slowa, liczba_slow):
    words = text.split()
    bez_dlugich = usun_dlugie(words, dl_slowa)  # -> tablica
    losowe = usun_losowe(bez_dlugich, liczba_slow)

    return " ".join(losowe)


tekst = "Podział peryklinalny inicjałów wrzecionowatych \
kambium charakteryzuje się ścianą podziałową inicjowaną \
w płaszczyźnie maksymalnej."

# print(uprosc_zdanie(tekst, 10, 5))


tekst2 = "Litwo! Ojczyzno moja! ty jesteś jak zdrowie.\
Ile cię trzeba cenić, ten tylko się dowie,\
Kto cię stracił. Dziś piękność twą w całej ozdobie\
Widzę i opisuję, bo tęsknię po tobie.\
\
Panno Święta, co Jasnej bronisz Częstochowy\
I w Ostrej świecisz Bramie! Ty, co gród zamkowy\
Nowogródzki ochraniasz z jego wiernym ludem!\
Jak mnie dziecko do zdrowia powróciłaś cudem\
(Gdy od płaczącej matki pod Twoję opiekę\
Ofiarowany, martwą podniosłem powiekę\
I zaraz mogłem pieszo do Twych świątyń progu\
Iść za wrócone życie podziękować Bogu),\
Tak nas powrócisz cudem na Ojczyzny łono.\
Tymczasem przenoś moję duszę utęsknioną\
Do tych pagórków leśnych, do tych łąk zielonych,\
Szeroko nad błękitnym Niemnem rozciągnionych;\
Do tych pól malowanych zbożem rozmaitem,\
Wyzłacanych pszenicą, posrebrzanych żytem;\
Gdzie bursztynowy świerzop, gryka jak śnieg biała,\
Gdzie panieńskim rumieńcem dzięcielina pała,\
A wszystko przepasane, jakby wstęgą, miedzą\
Zieloną, na niej z rzadka ciche grusze siedzą."

print(uprosc_zdanie(tekst2, 10, 50))

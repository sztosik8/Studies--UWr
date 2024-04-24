# Katarzna Trzos
# Lista 2
# Zadnaie 1


def filter_prog_wyborczy(wszystkie_glosy, glosy):
    prog_wyborczy = 5 * wszystkie_glosy / 100
    new_glosy = []
    for ile in glosy:
        if (ile[1] >= prog_wyborczy):
            new_glosy.append(ile)
    return new_glosy


def wyniki(glosy, mandaty):
    wszystkie_glosy = 0
    # policz ile w sumie oddanych glosow
    for komitet, ilosc in glosy:
        wszystkie_glosy += ilosc

    ilorazy_wyborcze = []
    # wyklucz komitety ktore nie przekroczyly progu
    glosy = filter_prog_wyborczy(wszystkie_glosy, glosy)
    ile_komitetow = len(glosy)

    for i in range(1, mandaty+2):
        for komitet, ilosc in glosy:
            ilorazy_wyborcze.append((round((ilosc/i), 3), komitet))

    ilorazy_wyborcze = sorted(ilorazy_wyborcze, key=lambda x: x[0])
    ilorazy_wyborcze = ilorazy_wyborcze[-mandaty:]

    # Inicjalizacja słownika do zliczania mandatów dla każdej partii
    mandaty_dla_komitetu = {}
    for komitet, ilosc in glosy:
        mandaty_dla_komitetu[komitet] = 0

    # Przydzielanie mandatów do partii na podstawie ilorazów wyborczych
    for iloraz, partia in ilorazy_wyborcze:
        mandaty_dla_komitetu[partia] += 1

    return mandaty_dla_komitetu


glosy2 =  [("pis", 7584121), ("ko", 6498786),
          ("3 droga", 3072263), ("lewica", 1823400), ("konfederacja", 1522515), ("bezpartyjni", 396885)]

#glosy1 = [("pis",123511 ), ("ko",110282 ),
         # ("3 droga", 38631), ("lewica", 49405), ("konfederacja", 22872), ("bezpartyjni", 11103)]

#print(wyniki(glosy1, 11))
print(wyniki(glosy2, 460))



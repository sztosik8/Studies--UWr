# Katarzyna Trzos
# Lista 1
# Zadanie 1

import decimal as d

# lista niespelniajaca rownosci (vat_faktura(zakupy) == vat_paragon(zakupy))
zakupy1 = [15.99, 5.49, 2.99, 8.95, 3.50, 9.99]
# list aspelniajaca rownosc
zakupy2 = [2.49, 1.99, 3.49, 4.99, 2.79]


def vat_faktura(lista):
    sum = 0
    for i in lista:
        sum += i

    number = d.Decimal(sum * 23/100)
    return (number.quantize(d.Decimal("0.00")))


def vat_paragon(lista):
    sum = 0
    for i in lista:
        number = d.Decimal(i * 23/100)
        sum += (number.quantize(d.Decimal("0.00")))
    return sum


# -----TESTY-------
""""
print(vat_faktura(zakupy1) == vat_paragon(zakupy1))
print(vat_faktura(zakupy2) == vat_paragon(zakupy2))
"""

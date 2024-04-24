# Katarzyna Trzos
# Lista 1
# Zadanie 2

import math
import string


def is_palindrom(text):
    text = text.lower()             # zamiana liter na male
    text = text.replace(" ", "")        # pozbycie sie znakow bialych
    text = only_letters(text)          # pozbycie sie znakow interpunkcyjnych

    length = len(text)
    for i in range(math.floor(length/2)):
        if (text[i] != text[length-i-1]):
            return False
    return True


def only_letters(string):
    result = ""
    for char in string:
        if char.isalpha():
            result += char

    return result


# -----TESTY-------
"""""
print(is_palindrom("K a  j     ak  "))
print(is_palindrom("Míčím"))
print(is_palindrom("Kłajałk"))
print(is_palindrom("Kobyła ma mAły BOk"))
print(is_palindrom("Eine güldne, gute.. Tugend: Lüge nie!"))
print(is_palindrom("Eine güldne gute Tugend Lüge nie"))
"""

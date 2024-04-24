from itertools import permutations

def is_valid(words, result, mapping):
    word_values = []
    for word in words:
        value = 0
        for letter in word:
            value = value * 10 + mapping[letter]
        word_values.append(value)
    
    result_value = 0
    for letter in result:
        result_value = result_value * 10 + mapping[letter]
    
    return sum(word_values) == result_value

def solve_cryptarithmetic(words, result):
    unique_letters = set("".join(words + [result]))
    if len(unique_letters) > 10:
        return None  # Za dużo unikalnych liter, nie da się rozwiązać
        
    for perm in permutations(range(10), len(unique_letters)):
        mapping = {letter: digit for letter, digit in zip(unique_letters, perm)}
        if mapping[result[0]] == 0:
            continue  # Wynik nie może zaczynać się od zera
        if is_valid(words, result, mapping):
            return mapping
    
    return None  # Brak rozwiązania

# Przykładowe dane wejściowe
words = ["KIOTO", "OSAKA"]
result = "TOKIO"

solution = solve_cryptarithmetic(words, result)
if solution:
    print("Rozwiązanie znalezione:")
    for letter, digit in solution.items():
        print(f"{letter}: {digit}")
else:
    print("Brak rozwiązania")

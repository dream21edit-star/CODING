sentence = "Learning Python is fun"
counter = 0
vowels = ['a','e','i','o','u']

def count_vowels(sentence, vowels):
    counter = 0
    lsentence = sentence.lower()
    for char in lsentence:
        if char in vowels:
            counter += 1
    print("counter = ", counter)
count_vowels(sentence, vowels)
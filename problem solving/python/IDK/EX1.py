
def ex1(a, b):
    if a*b <= 1000:
        return a*b
    else:
        return a+b
    
a = int(input("a = "))
b = int(input("b = "))

r = ex1(a, b)
print("le resultat est " + str(r))
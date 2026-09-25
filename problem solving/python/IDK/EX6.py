n = 5
f = 1
def factorial(n, f):
    for i in range(1, n+1):
        f *= i
    print("n = ", f)
factorial(n, f)
numbers = range(10)
k = 0
for c in numbers:
    sum = k + c
    print("Current number: " + str(c) + " Previous number: " + str(k) + " Sum: " + str(sum))
    k = c
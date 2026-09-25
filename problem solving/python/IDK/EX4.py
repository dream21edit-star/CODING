data = "pynative"
n = int(input("n = "))
def remove_chars(data, n):
    res = data[n:]
    return res
print(remove_chars(data, n))
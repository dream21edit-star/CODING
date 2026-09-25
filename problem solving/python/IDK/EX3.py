data = "pynative"
start = 0
step = 2
stop = len(data) - 1
pos = 0
print("Printing only even index chars")
for i in data:
    if pos==start and start <= stop:
        print(i)
        start += step
    pos += 1
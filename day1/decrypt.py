floor = 1
count = 0

with open ("input.txt", "r") as myfile:
    for c in myfile.read():
        count += 1
        floor += 1 if c == '(' else -1
        if floor == -1:
            print("entered basement at: " + str(count-1))

    print(str(floor))

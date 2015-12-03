paper = 0
ribbon = 0

with open("input.txt", "r") as myfile:
    for line in myfile.read().split("\n"):
        temp = ""
        #     [L,W,H] aka Length Width Height
        dim = [0,0,0]
        i = 0
        line += "x"
        for c in line:
            if c == 'x' and not temp == '':
                dim[i] = int(temp)
                i += 1
                temp = ""
            else:
                temp += c

        paper += (2 * dim[0] * dim[1]) + (2 * dim[1] * dim[2]) + (2 * dim[2] * dim[0]) + (min(min(dim[0] * dim[1], dim[1] * dim[2]), dim[2] * dim[0] ))
        ribbon += (min(min(2 * dim[0] + 2 * dim[1], 2 * dim[1] + 2 * dim[2]), 2 * dim[2] + 2 * dim[0])) + (dim[0] * dim[1] * dim[2])

print(str(paper) + " square feet of wrapping paper")
print(str(ribbon) + " square feet of ribbon")

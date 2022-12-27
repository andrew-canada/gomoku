f = open("in.txt", "r")

max_cals = 0
temp_max = 0
for line in f:
    if line == "\n":
        max_cals = max(max_cals, temp_max)
        temp_max = 0
    else:
        temp_max += int(line)
print(max_cals)
f.close()

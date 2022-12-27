f = open("in.txt", "r")

first = 0
second = 0
third = 0
temp_max = 0
for line in f:
    if line == "\n":
        if temp_max > first:
            first = temp_max
        elif first > temp_max > second:
            second = temp_max
        else:
            third = temp_max
    else:
        temp_max += int(line)
print(first + second + third)
f.close()

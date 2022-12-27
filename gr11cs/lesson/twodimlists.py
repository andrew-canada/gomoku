a = [[1, 2], [3, 4]]
print("Whole list:", a)
print("List 1:", a[0])
print("List 2:", a[1])

print("List 1, element 1:", a[0][0])

b = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

# print row 1
print(b[1])

# access and print 6
print(b[1][2])

# access and print 8
print(b[2][1])

# access and print col 1
for i in range(3):
    print(b[i][1])

print(b[:][1])  # prints row 1
print(b[1][1:])  # prints elements in row 1, starting from element 1

for row in b:
    print(row)

for row in b:
    for item in row:
        print(item, end=" ")
    print()

for r in range(len(b)):
    for c in range(len(b[r])):
        print(b[r][c], end=" ")
    print()

# change the 5 to a 12
b[1][1] = 12

# change the 7 to a -2
b[2][0] = -2

# increase each element by 100
for i in range(len(b)):
    for j in range(len(b[i])):
        b[i][j] += 100

print(b)

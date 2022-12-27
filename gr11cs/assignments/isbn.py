isbn = input("Enter an ISBN: ")
sum = 0

weight = 10
for digit in isbn:
  sum += weight * (ord(digit) - 48)
  if digit == "X" or digit == "x":
    sum += 10
  weight -= 1

print("a")
import random

# 1: Experiment with random; what is random
# Random sets a seed based on the time to generate a random decimal number between 0 and 1
for i in range(5):
    print(random.random())

# 2. Use random() to print 10 floats within some ranges
print("# 2. ")
print("4 to 5")
for i in range(10):
    num = random.random() + 4
    if num == 5:
        print(random.random() + 4)
    else:
        print(num)
print("0 to 10")
for i in range(10):
    num = random.random() * 10
    if num == 10:
        print(random.random() * 10)
    else:
        print(num)
print("20 to 30")
for i in range(10):
    num = random.random() * 10 + 20
    if num == 30:
        print(random.random() * 10 + 20)
    else:
        print(num)
print("x to y")
x = int(input("Enter x: "))
y = int(input("Enter y: "))
for i in range(10):
    num = random.random() * (y - x) + x
    if num == y:
        print(random.random() * (y - x) + x)
    else:
        print(num)

print("# 3. ")
# 3. Experiment with randrange(start, stop[, step])
for i in range(10):
    print(random.randrange(1, 10))
print("--")
for i in range(10):
    print(random.randrange(1, 10, 2))

print("# 4. ")
# 4. Random even integers between 1 and 1000
print("Even integers between 1 and 1000")
for i in range(10):
    print(random.randrange(1, 500) * 2)
print("Multiples of 7 between 1 and 1000")
for i in range(10):
    print(random.randrange(1, 142) * 7)

# 6. The relationship between randint() and randrange()
# randrange() is the same as randint() but with an optional field for the increment step

print("# 7.")
# 7. Guessing game
number = random.randint(1, 10)
print("I have a number between 1 and 10. Can you guess it?")
isGuessed = False

for i in range(2, -1, -1):
    guess = int(input())
    if guess != number:
        print("That's not right")
        if guess > number:
            print("The number is lower than your guess")
        else:
            print("The number is higher than your guess")
        print("Guess again ({} attempts remaining)".format(i))
    else:
        print("That's right")
        isGuessed = True
        break
if not isGuessed:
    print("That's not right")
    if guess > number:
        print("The number is lower than your guess")
    else:
        print("The number is higher than your guess")
    print("0 attempts remaining")
    print("The number was {}".format(number))

print("# 8.")
# 8. Roll a 6-sided dice until the same number occurs again
isContinue = True
roll = ""
value = -1
newValue = -1
numRolls = 0
yesOrNo = ""
while isContinue:
    roll = input("Click \"r\" to roll a dice: ").lower()
    if roll == "r":
        value = random.randint(1, 6)
        print("You rolled a {}".format(value))
        while value != newValue:
            roll = input("Click \"r\" to roll again: ").lower()
            newValue = random.randint(1, 6)
            print("You rolled a {}".format(newValue))
            numRolls += 1
    print("{} rolls after your initial roll, you reached the initial value again".format(numRolls))
    yesOrNo = input("Play again (y/n)? ").lower()
    if yesOrNo == "y":
        isContinue = True
    elif yesOrNo == "n":
        isContinue = False
    else:
        print("Invalid input... no more playing")
        break

print("# 9.")
# 9. Guessing game but with user picking a number and program guessing
number = int(input("Pick a number between 1 and 10: "))
guess = 5
isGuessed = False
low = 1
high = 10
for i in range(4):
    print("Is the number {}? ".format(guess))
    response = input().lower()
    if response == "correct":
        isGuessed = True
        break
    elif response == "lower":
        high = guess - 1
        guess = (low + high) // 2
    else:
        low = guess + 1
        guess = (low + high) // 2

print("# 10.")
# 10.
# Can always win within 7 guesses (binary search)
number = int(input("Pick a number between 1 and 100: "))
guess = 50
isGuessed = False
low = 1
high = 100
for i in range(7):
    print("Is the number {}? ".format(guess))
    response = input().lower()
    if response == "correct":
        isGuessed = True
        break
    elif response == "lower":
        high = guess - 1
        guess = (low + high) // 2
    else:
        low = guess + 1
        guess = (low + high) // 2

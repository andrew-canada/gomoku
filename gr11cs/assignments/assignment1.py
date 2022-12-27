# Greeting
# Ask the user for their name and birth year
#   Print a greeting with the user's name and age
# Author: Andrew Peng
name = input("Enter your name: ")
birth_year = int(input("Enter your birth year: "))
age = 2017 - birth_year
print("Hello {}! You are {} years old.".format(name, age))

# Rectangle Facts
# Ask the user for the length and width of a rectangle
#   Print the area and perimeter of the rectangle
# Author: Andrew Peng
length = float(input("Enter the length: "))
width = float(input("Enter the width: "))
area = length * width
perimeter = 2 * (length + width)
print("The area of the rectangle is {}, and the perimeter is {}.".format(format(area, '.6f'), format(perimeter, '.6f')))

import math
# Pythagoras
# Ask the user for the lengths of the legs of a right triangle
#   Calculate and print the length of the hypotenuse
# Author: Andrew Peng
lengthSide1 = float(input("Enter the first length: "))
lengthSide2 = float(input("Enter the second length: "))
hypotenuse = math.sqrt(lengthSide1**2 + lengthSide2**2)
print("The hypotenuse is {}.".format(round(hypotenuse, 6)))

# Challenge
# Ask the user for a word
#   Convert the word to 3 different states: all upper case, all lower case, and capitalized first letter
#   Print the 3 transformed words
# Author: Andrew Peng
word = input("Enter a word: ")

## all lowercase
wordAllLower = ""
for count, character in enumerate(word):
  if ord(character) >= 97:
    wordAllLower += character
  else:
    # the difference between the ascii of uppercase and lowercase is 32
    wordAllLower += chr(ord(character) + 32)
print("Word with all lowercase: {}".format(wordAllLower))

# all uppercase
wordAllUpper = ""
for count, character in enumerate(wordAllLower):
  wordAllUpper += chr(ord(character) - 32)
print("Word with all uppercase: {}".format(wordAllUpper))

# capitalized
wordCapitalized = wordAllUpper[0]
wordCapitalized += wordAllLower[1:len(wordAllLower)]
print("Word capitalized: {}".format(wordCapitalized))
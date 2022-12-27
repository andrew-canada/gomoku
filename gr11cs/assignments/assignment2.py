# Birthday
# Get the user's birth month and day, get the current month and day from the user; see if the birthday has passed, is yet to come, or is today.
# Author: Andrew Peng

import sys

birth_day = int(input("Enter your birth day: "))
if birth_day < 1 or birth_day > 31:
  sys.exit("Invalid input!")
birth_month = int(input("Enter your birth month: "))
if birth_month < 1 or birth_day > 12:
  print("Invalid input!")
  sys.exit("Invalid input!")
current_day = int(input("Enter today's day: "))
current_month = int(input("Enter today's month: "))

# check if the birthday is in the same month as it is today
if birth_month > current_month:
  print("Your birthday is approaching. Happy early birthday!")
elif birth_month < current_month:
  print("Your birthday has passed. Happy belated birthday!")
# check if the day is before or after today's day
else:
  if birth_day > current_day:
    print("Your birthday is approaching. Happy early birthday!")
  elif birth_day < current_day:
    print("Your birthday has passed. Happy belated birthday!")
  else:
    print("Happy birthday!")

# -------------------------

# Quadratic equation solver
# a) Ask the user for the coefficients and constants of a quadratic equation (3 values in total)
  # Calculate the discriminant and print the number of solutions
# b) Ask the user for the coefficients and constants of a quadratic equation (3 values in total)
  # Calculate the roots and the equation with the quadratic formula and print them
# Author: Andrew Peng

# sqrt() function will be needed for quadratic formula
import math

# a)
print("Enter the values of a, b, and c from the equation ax^2 + bx + c = 0:")
valA = float(input("a = "))
valB = float(input("b = "))
valC = float(input("c = "))

# discriminant = b^2 - 4*a*c
# the quadratic formula requires the square root of the discriminant
discriminant = valB**2 - 4 * valA * valC

# the quadratic formula can add or subtract the square root of the discriminant -> 2 solutions
if discriminant > 0:
  print("\nThere are two solutions.\n")
# the quadratic formula works without the square root of the discriminant -> 1 solution
elif discriminant == 0:
  print("\nThere is one solution.\n")
# the square root of a negative number doesn't exist -> no solutions
else:
  print("\nThere are no solutions.\n")

# b
print("Enter the values of a, b, and c from the equation ax^2 + bx + c = 0:")
valA = float(input("a = "))
valB = float(input("b = "))
valC = float(input("c = "))

# discriminant = b^2 - 4*a*c
# the quadratic formula requires the square root of the discriminant
discriminant = valB**2 - 4 * valA * valC

# quadratic formula: (-b ±√(b^2-4ac))/2a
# if the discriminant is positive, there are 2 solutions. if it is equal to 0, there is 1 solution. if it is negative, there are no solutions

# positive discriminant
if discriminant > 0:
  root1 = (-valB + math.sqrt(discriminant)) / (2*valA)
  root2 = (-valB - math.sqrt(discriminant)) / (2*valA)
  print("\nThe roots are {:.2f} and {:.2f}.".format(root1, root2))
elif discriminant == 0:
  root = -valB / (2*valA)
  print("\nThe root is {:.2f}.".format(root))
else:
  print("\nThere are no roots")

# -------------------------

# Challenge: Leap Year Calculator
# a) Ask the user for a year. Determine if the year is a leap year.
# b) Ask the user for 2 dates (ddmmyyyy). Determine the the number of days between the 2 days (inclusive of the days).
# Author: Andrew Peng

# a)
year = int(input("Enter a year: "))
if year % 4 == 0:
  if year % 100 == 0:
    # if a year is a multiple of 100, it must also be a multiple of 400 to be a leap year
    if year % 400 == 0:
      print("The year {} is a leap year.\n".format(year))
    else:
      print("The year {} is not a leap year.\n".format(year))
  # if a year is a multiple of 4 and it isn't a multiple of 100, it is a leap year
  else:
    print("The year {} is a leap year.\n".format(year))
else:
  print("The year {} is not a leap year.\n".format(year))

# b)
days_per_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

date1 = int(input("Enter the first date (ddmmyyyy format): "))
date2 = int(input("Enter the second date (ddmmyyyy format): "))

# using division, modulos, and multiplication, extract the days, months, and years from each ddmmyyyy format date
day1 = date1 // 1000000
month1 = (date1 // 100000 % 10 * 10) + (date1 // 10000 % 10)
year1 = (date1 % 10000)

day2 = date2 // 1000000
month2 = (date2 // 100000 % 10 * 10) + (date2 // 10000 % 10)
year2 = (date2 % 10000)

# find the total amount of days in each date, then subtract them
# get the number of days in the years preceding and including the date's year. add the days in the date
total_days_1 = year1 * 365 + day1

# add the days in the months before the date's month
for i in range(0, month1 - 1):
  total_days_1 += days_per_month[i]

# add 1 day for each leap year that occurred before the date
# the effect of a leap year will only be seen after february (which has 29 days in a leap year)
if month1 <= 2:
  year1 -= 1
# a leap year must be divisible by 4, but if it is divisible by 100, it must also be divisible by 400. 
# subtract the ones that are divisible by 100 because the leap years that are divisible by 100 are included in the divisible by 400
total_days_1 += year1 // 4 + year1 // 400 - year1 // 100

# same process for 2nd date
total_days_2 = year2 * 365 + day2

for i in range(0, month2 - 1):
  total_days_2 += days_per_month[i]

if month2 <= 2:
  year2 -= 1

total_days_2 += year2 // 4 + year2 // 400 - year2 // 100

# print the difference
if total_days_1 > total_days_2:
  difference1 = total_days_1 - total_days_2
  if difference1 > 1:
    print("There are {} days between {} and {}.".format(difference1, date1, date2))
  else:
    print("There is {} day between {} and {}.".format(difference1, date1, date2))
else:
  difference2 = total_days_2 - total_days_1
  if difference2 > 1:
    print("There are {} days between {} and {}.".format(difference2, date1, date2))
  else:
    print("There is {} day between {} and {}.".format(difference2, date1, date2))

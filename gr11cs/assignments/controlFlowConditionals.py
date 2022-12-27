# 1. Get 2 integers and check if they are equal
num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))

if num1 == num2:
    print("The numbers are equal")
else:
    print("The numbers aren't equal")

# 2. Get 1 number. 
#    If between 0 and 100 (exclusive), print "high".
#    -100 to 0, print "low"
#    0, print "zero"
#    none of the above, print "outside"
num3 = float(input("Enter a number: "))

if 0 < num3 < 100:
    print("high")
elif -100 < num3 < 0:
    print("low")
elif num3 == 0:
    print("zero")
else:
    print("outside")

# 3. Get 1 integer and check if it is even
num4 = int(input("Enter a number: "))

if num4 % 2 == 0:
    print("The number is even")
else:
    print("The number is odd")

# 4. Get 1 integer. Check its sign and if it's even or odd
num5 = int(input("Enter a number: "))
if num5 % 2 == 0:
    print("The number {} is even and ".format(num5), end="")
else:
    print("The number {} is odd and".format(num5), end="")
if num5 > 0:
    print("positive.")
else:
    print("negative.")

# 5. Get 2 integers, print both numbers, and state which was largest
num6 = int(input("Enter the first number: "))
num7 = int(input("Enter the second number: "))
if num6 > num7:
    print("{} is the largest, out of {} and {}.".format(num6, num7, num6))
else:
    print("{} is the largest, out of {} and {}.".format(num7, num6, num7))

# 6. a) Find triangle type based on angles
angle1 = int(input("Enter the first angle measurement: "))
angle2 = int(input("Enter the second angle measurement: "))
angle3 = int(input("Enter the third angle measurement: "))
if angle1 + angle2 + angle3 == 180 and angle1 > 0 and angle2 > 0 and angle3 > 0:
    if angle1 == 90 or angle2 == 90 or angle3 == 90:
        print("Right ", end="")
    if(angle1 == angle2 and angle2 == angle3):
        print("equilateral triangle")
    elif(angle1 != angle2 and angle2!= angle3 and angle1 != angle3):
        print("scalene triangle")
    else:
        print("isosceles triangle")
else:
    print("Not a triangle")

# 6. b) Find triangle type based on side lengths
side1 = int(input("Enter the first side length: "))
side2 = int(input("Enter the second side length: "))
side3 = int(input("Enter the third side length: "))

if side1 > 0 and side2 > 0 and side3 > 0:
    if side1 == side2 and side2 == side3:
        print("Equilateral triangle")
    elif side1 != side2 and side2 != side3 and side1 != side3:
        print("Scalene triangle")
    else:
        print("Isosceles triangle")
else:
    print("Not a triangle")

# 7. Get a month number and display the number of days in that month
month_number = int(input("Enter the month number (e.g., 1 for January): "))

if month_number == 2:
    print("Month 2 has 28 days")
elif month_number == 4 or month_number == 6 or month_number == 9 or month_number == 11:
    print("Month {} has 30 days".format(month_number))
else:
    print("Month {} has 31 days".format(month_number))

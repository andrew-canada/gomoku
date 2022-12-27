#@title This block will be used for testing your program. Currently, it doesn't work and will only break your code.
#lines = ['1','1','3','3','\n']
lines = ["hi",'1','1',"190","50","20","-5","5",'2',"5","10","45",'2',"2","3","34",'2',"11","10","60",'3','2','1',"10",
         "20","1",'2',"10","20","","1",'2',"20","2","10",'2',"2","20","10",'2',"25","20","10",'3','3']
line_number = 0


def input(prompt):
    global line_number
    global lines
    print(prompt)

    line_number+=1
    print(lines[line_number-1])
    return lines[line_number-1]


"""
Trigonometry Calculator: Sine and Cosine Law
Template by: Mr Cho

"""

__author__ = "Andrew Peng"


# import statement
from math import sin, cos, asin, acos, degrees, radians, sqrt


###--- define trig functions in degrees ---###
###--- don't change!                    ---###
def sin_(x):
    return sin(radians(x))


def cos_(x):
    return cos(radians(x))


def asin_(x):
    return degrees(asin(x))


def acos_(x):
    return degrees(acos(x))


###--- functions for menus: don't change!   ---###
###--- may change some text that is printed ---###
###--- add descriptions, etc.               ---###

def main_menu():
    """Execute main menu."""

    while True:
        print("""
  Trigonometry Calculator
  -+-+-+-+-+-+-+-+-+-+-+-

  Choose an option:

  1. Sine Law Calculator
  2. Cosine Law Calculator

  3. Exit Program

    """)
        choice = input('> ') # can change this
        if choice == '1':
            sine_law_menu()
        elif choice == '2':
            cosine_law_menu()
        elif choice == '3':
            print('\033[1mThank you for using the Trig Calculator!\033[0m') # change this
            break
        else:
            print('\033[1mInvalid choice.\033[0m') # can change this


# runs sine law calculator
def sine_law_menu():
    """Execute cosine law menu."""

    while True:
        print("""
    Sine Law Calculator
    /\/\/\/\/\/\/\/\/\/

    Choose an option:

    1. Angle - Angle - Side (AAS)
    2. Side - Side - Angle (SSA)
    
    3. Exit to Main Menu

    """)
        choice = input('  > ') # can change this
        if choice == '1':
            sine_law_AAS()
        elif choice == '2':
            sine_law_SSA()
        elif choice == '3':
            break
        else:
            print('Invalid choice.') # can change this

# runs cosine law calculator
def cosine_law_menu():
    """Execute cosine law menu."""

    while True:
        print("""
    Cosine Law Calculator
    \/\/\/\/\/\/\/\/\/\/\

    Choose an option:

    1. Side - Angle - Side (SAS)
    2. Side - Side - Side (SSS)

    3. Exit to Main Menu

    """)
        choice = input('  > ') # can change this
        if choice == '1':
            cosine_law_SAS()
        elif choice == '2':
            cosine_law_SSS()
        elif choice == '3':
            break
        else:
            print('Invalid choice.') # can change this


#####################################
###--- complete the code below ---###
#####################################

def wait():
    """A simple function to pause the output."""

    input('\nPress enter to continue...\n') # can change the message


# fail-safe floating-point input function(s)

    # write your code here
def get_float(prompt: str) -> float:
    # loops until input is valid
    while True:
        try:
            value = float(input(prompt))
            return value
        # input can't be casted to float
        except ValueError:
            print("Invalid input. Try again.")


def get_angle(prompt: str) -> float:
    angle = get_float(prompt)
    while angle >= 180:
        print("Each angle in a triangle must be < 180\xb0. Try again.")
        angle = get_float(prompt)
    return angle


def get_side(prompt: str) -> float:
    side = get_float(prompt)
    while side <= 0:
        print("Sides must have positive lengths. Try again.")
        side = get_float(prompt)
    return side


## You MUST take inputs in the order as described
## in the Menu Structure drawing (see Assignment)

def sine_law_AAS():
    """Execute Sine Law (AAS) code."""

    angle_a = get_angle("Enter the measure (in degrees) of angle A: ")
    angle_b = get_angle("Enter the measure (in degrees) of angle B: ")
    side_a = get_side("Enter the length of side a: ")

    # derived from: b/sin(B) = a/sin(A)
    side_b = side_a * sin_(angle_b) / sin_(angle_a)
    print("\n\033[1mThe length of side b is: {}\033[0m".format(round(side_b, 2)))

    # solution to the entire triangle
    angle_c = 180 - angle_a - angle_b
    side_c = side_a * sin_(angle_c) / sin_(angle_a)
    print("\nSolution to the entire triangle: ")
    print("angle a: {}\xb0, angle b: {}\xb0, angle c: {}\xb0".format(round(angle_a, 1), round(angle_b, 1), round(angle_c, 1)))
    print("side a: {}, side b: {}, side c: {}".format(round(side_a, 2), round(side_b, 2), round(side_c, 2)))


def sine_law_SSA():
    """Execute Sine Law (SSA) code."""

    side_a = get_side("Enter the length of side a: ")
    side_b = get_side("Enter the length of side b: ")
    angle_a = get_angle("Enter the measure (in degrees) of angle A: ")

    # this value must be less than 1, the max sine value (in degrees) is 1
    val_to_arcsin = sin_(angle_a) * side_b / side_a

    if val_to_arcsin <= 1:
        angle_b = asin_(sin_(angle_a) * side_b / side_a)
        # the other possible angle measure
        ambiguous_b = 180 - angle_b
        # check if the sum of the 2 angles is less than 180 (adjusted for float imprecision)
        if ambiguous_b + angle_a - 180 < 0.000001:
            print("\n\033[1mAmbiguous case: there are two possible measures for angle b: \033[0m")
            print("\033[1mThe first measure of angle b (in degrees) is: {}\xb0\033[0m".format(round(angle_b, 1)))
            print("\033[1mThe second measure of angle b (in degrees) is: {}\xb0\033[0m".format(round(ambiguous_b, 1)))

            # 2 solutions to the entire triangle
            angle_c1 = 180 - angle_a - angle_b
            side_c1 = side_a * sin_(angle_c1) / sin_(angle_a)

            angle_c2 = 180 - angle_a - ambiguous_b
            side_c2 = side_a * sin_(angle_c2) / sin_(angle_a)
            print("\n2 solutions to the entire triangle: ")
            print("Solution 1: ")
            print("angle a: {}\xb0, angle b: {}\xb0, angle c: {}\xb0".format(round(angle_a, 1), round(angle_b, 1),
                                                                             round(angle_c1, 1)))
            print("side a: {}, side b: {}, side c: {}".format(round(side_a, 2), round(side_b, 2), round(side_c1, 2)))

            print("Solution 2: ")
            print("angle a: {}\xb0, angle b: {}\xb0, angle c: {}\xb0".format(round(angle_a, 1), round(ambiguous_b, 1),
                                                                             round(angle_c2, 1)))
            print("side a: {}, side b: {}, side c: {}".format(round(side_a, 2), round(side_b, 2), round(side_c2, 2)))

        else:
            print("\n\033[1mThe measure of angle b (in degrees) is: {}\xb0\033[0m".format(round(angle_b, 1)))

            # solution to the entire triangle
            angle_c = 180 - angle_a - angle_b
            side_c = side_a * sin_(angle_c) / sin_(angle_a)
            print("\nSolution to the entire triangle: ")
            print("angle a: {}\xb0, angle b: {}\xb0, angle c: {}\xb0".format(round(angle_a, 1), round(angle_b, 1),
                                                                             round(angle_c, 1)))
            print("side a: {}, side b: {}, side c: {}".format(round(side_a, 2), round(side_b, 2), round(side_c, 2)))

    else:
        print("\n\033[1mThere is no valid solution.\033[0m")


def cosine_law_SAS():
    """Execute Cosine Law (SAS) code."""

    side_a = get_side("Enter the length of side a: ")
    side_b = get_side("Enter the length of side b: ")
    angle_a = get_angle("Enter the measure (in degrees) of angle A: ")

    # derived from cosine law
    side_c = sqrt(side_a**2 + side_b**2 - 2 * side_a * side_b * cos_(angle_a))
    print("\n\033[1mThe length of side c is: {}\033[0m".format(round(side_c, 2)))

    # solution to the entire triangle
    angle_b = acos_((side_a**2 + side_c**2 - side_b**2)/(2*side_a*side_c))
    angle_c = 180 - angle_a - angle_b
    print("\nSolution to the entire triangle: ")
    print("angle a: {}\xb0, angle b: {}\xb0, angle c: {}\xb0".format(round(angle_a, 1), round(angle_b, 1), round(angle_c, 1)))
    print("side a: {}, side b: {}, side c: {}".format(round(side_a, 2), round(side_b, 2), round(side_c, 2)))


def cosine_law_SSS():
    """Execute Cosine Law (SSS) code."""

    side_a = get_side("Enter the length of side a: ")
    side_b = get_side("Enter the length of side b: ")
    side_c = get_side("Enter the length of side c: ")

    # the longest side must be longer than the sum of the lengths of the other 2 sides to form a triangle
    sides = [side_a, side_b, side_c]
    max_side = max(sides)
    sides.remove(max_side)
    if sides[0] + sides[1] > max_side:
        angle_c = acos_((side_a**2 + side_b**2 - side_c**2) / (2 * side_a * side_b))
        print("\n\033[1mThe measure of angle c (in degrees) is: {}\xb0\033[0m".format(round(angle_c, 1)))

        # solution to the entire triangle
        angle_a = acos_((side_b**2 + side_c**2 - side_a**2)/(2*side_b*side_c))
        angle_b = acos_((side_a ** 2 + side_c ** 2 - side_b ** 2) / (2 * side_a * side_c))
        angle_c = 180 - angle_a - angle_b
        print("\nSolution to the entire triangle: ")
        print("angle a: {}\xb0, angle b: {}\xb0, angle c: {}\xb0".format(round(angle_a, 1), round(angle_b, 1),
                                                                         round(angle_c, 1)))
        print("side a: {}, side b: {}, side c: {}".format(round(side_a, 2), round(side_b, 2), round(side_c, 2)))
    else:
        print("\n\033[1mThat triangle doesn't exist. Make sure a + b < c\033[0m")



##########################
###--- main program ---###
##########################

if __name__ == '__main__':
    main_menu()

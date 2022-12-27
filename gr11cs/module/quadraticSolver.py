# Start module with description comments
"""
Quadratic equation solver
Description: Get values of coefficients of a quadratic equation and provide solutions
"""

# Set variable for author
__author__ = "Andrew Peng"

# Import statements
# sqrt() function will be needed for quadratic formula
import math


def discriminant(valA, valB, valC):
    """discriminant = b^2 - 4*a*c
    Return the discriminant of the quadratic formula
    """

    return valB**2 - 4 * valA * valC


def num_solutions(valA, valB, valC):
    """Return the number of solutions for a quadratic with coefficients valA, valB, valC
    """

    dis = discriminant(valA, valB, valC)
    # the quadratic formula can add or subtract the square root of the discriminant -> 2 solutions
    if dis > 0:
        return 2
    # the quadratic formula works without the square root of the discriminant -> 1 solution
    elif dis == 0:
        return 1
    # the square root of a negative number doesn't exist -> no solutions
    else:
        return 0


def solve(valA, valB, valC):
    """Print the solutions to a quadratic with coefficients valA, valB, and valC.
    """
    num = num_solutions(valA, valB, valC)

    # discriminant = b^2 - 4*a*c
    # the quadratic formula requires the square root of the discriminant
    dis = discriminant(valA, valB, valC)

    # quadratic formula: (-b ±√(b^2-4ac))/2a
    # if the discriminant is positive, there are 2 solutions. if it is equal to 0, there is 1 solution. if it is negative, there are no solutions

    # positive discriminant
    if num == 2:
        root1 = (-valB + math.sqrt(dis)) / (2*valA)
        root2 = (-valB - math.sqrt(dis)) / (2*valA)
        print("\nThe roots are {:.2f} and {:.2f}.".format(root1, root2))
    elif num == 1:
        root = -valB / (2*valA)
        print("\nThe root is {:.2f}.".format(root))
    else:
        print("\nThere are no roots")


def get_float(prompt):
    """Return a floating point number entered by the user from prompt"""

    try:
        x = float(input(prompt))
        return x
    except:
        return 0


def main():
    """Ask the user for the coefficients of a quadratic function and print the number of solutions, 
    as well as the solutions"""


    print("Enter the values of a, b, and c from the equation ax^2 + bx + c = 0:")
    valA = get_float("a = ")
    valB = get_float("b = ")
    valC = get_float("c = ")

    num = num_solutions(valA, valB, valC)
    print("The number of solutions is: {}".format(num))

    solve(valA, valB, valC)

    print(__author__)
    print(__name__)


if __name__ == "__main__":
    main()

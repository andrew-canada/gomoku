"""
ISBN-13 verifier and check-digit generator
Description: Get an ISBN-13 number and either verify 
    or generate the check digit of a number missing its 13th digit, based on the user's input
"""

__author__ = "Andrew Peng"



def clean(isbn_code):
    """
    Return ISBN code with all dashes ("-") removed
    """

    isbn_without_dashes = ""
    for char in isbn_code:
        if char != "-":
            isbn_without_dashes += char
    return isbn_without_dashes


def calc_weighted_sum(isbn_code):
    """
    Return the weighted sum of the digits of the ISBN code
    """

    isbn_without_dashes = clean(isbn_code)
    sum = 0
    count = 0
    for x in isbn_without_dashes:
        if count % 2 == 0:
            sum += int(x)
        else:
            sum += int(x) * 3 
        count += 1
    return sum


def is_valid(isbn_code):
    """
    Return a boolean value indicating if the ISBN code is valid
    """

    isbn_without_dashes = clean(isbn_code)
    sum = calc_weighted_sum(isbn_without_dashes)
    if sum % 10 == 0:
        return True
    else:
        return False


def generate_check_digit(isbn_without_check_digit):
    """
    Generate the check digit of an ISBN code that doesn't have a check digit
    """

    isbn_without_check_digit = clean(isbn_without_check_digit)
    sum = calc_weighted_sum(isbn_without_check_digit)
    for i in range(11):
        if (sum + i) % 10 == 0:
            check_digit = i
            break
    if check_digit == 10:
        check_digit = "X"
    return check_digit


def main():
    """
    Ask the user if they want to verify an ISBN or generate the check digit for an ISBN without a check digit
    """
    operation = input("Would you like to verify an ISBN or generate a check digit for an ISBN that doesn't have a check digit? ")
    isbn = input("Enter an ISBN: ")
    if operation == "verify":
        if is_valid(isbn):
            print("{} is a valid ISBN".format(isbn))
        else:
            print("{} is not a valid ISBN".format(isbn))
    elif operation == "generate":
        check_digit = generate_check_digit(isbn)
        print("The check digit for the ISBN {} is {}".format(isbn, check_digit))
        print("The complete ISBN is {}".format(isbn + str(check_digit)))


if __name__ == "__main__":
    main()

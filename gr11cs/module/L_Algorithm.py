"""
Credit card number verifier and check-digit generator
Description: Get an 16-digit credit care number and either verify 
    or generate the check digit of a number missing its 16th digit, 
    using the L-algorithm, based on the user's input
"""

__author__ = "Andrew Peng"


def check_validity(card_number):
  """
  Check if a 16-digit credit card number is valid with the "L" algorithm. 
  Return true if valid, false if not valid
  """

  sum = 0
  # Calculations start at the last digit
  for i in range(len(card_number)-1, -1, -1):
    digit = int(card_number[i])
    # Every second number is multiplied by 2
    if i % 2 == 0:
      if digit * 2 >= 10:
        # The sum of the digits of a 2-digit number is the value of that number - 9
        sum += digit * 2 - 9
      else:
        sum += digit * 2
    else:
      sum += digit

  if sum % 10 == 0:
    return True
  else:
    return False


def generate_checkdigit(card_number_without_checkdigit):
  """
  Generate and return the check digit of a 15-digit credit card number 
  (16-digit number missing the its last digit) with the "L" algorithm
  """

  sum = 0
  # Calculations start at the last digit
  for i in range(len(card_number_without_checkdigit)-1, -1, -1):
    digit = int(card_number_without_checkdigit[i])
    # Every second number is multiplied by 2
    if i % 2 == 0:
      if digit * 2 >= 10:
        # The sum of the digits of a 2-digit number is the value of that number - 9
        sum += digit * 2 - 9
      else:
        sum += digit * 2
    else:
      sum += digit

  for i in range(10):
    if (sum + i) % 10 == 0:
      return i


def main():
    print("Would you like to verify a 16-digit credit card number or generate the check digit of a number without its 16th digit?")
    action = input("Enter \"verify\" to verify or \"generate\" to generate: ")
    card_number = input("Enter your card number: ")
    if action == "verify":
        if check_validity(card_number):
            print("The card number {} is valid".format(card_number))
        else:
            print("The card number {} is not valid".format(card_number))
    elif action == "generate":
        print("The check digit of the card number {} is {}".format(card_number, generate_checkdigit(card_number)))
        print("The full card number is: {}".format(card_number + str(generate_checkdigit(card_number))))
    else:
        print("Invalid input")


if __name__ == "__main__":
  main()

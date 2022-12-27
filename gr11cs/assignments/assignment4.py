# 1 Complete the HEADER of this function (including type contract).(No EXAMPLES.) /1
def get_int(msg: str) -> int:
    """Return an int gotten from the user with input message msg.

    Validate input so that only integers are accepted."""

    while True:
        try:
            x = int(input(msg))
            return x
        except ValueError:
            print('Invalid input...')


# 2 Complete the DESCRIPTION of this function. (No EXAMPLES.) /1
def get_list_of_strings(n: int) -> str:
    """Return a list of n strings provided by the user, 
    given the number of strings n as function input.
    """
    strings = []
    for i in range(n):
        strings.append(input('> '))
    return strings


# 3 Complete the DESCRIPTION and BODY of this function. /2
def average_length(strs: str) -> float:
    """Return the average string length of a list of strings strs, provided by the user

    >>> average_length(['hi', 'hello'])
    3.5
    >>> average_length([])
    0
    """

    if len(strs) > 0:
        total = 0
        for string in strs:
            total += len(string)
        return total / len(strs)
    else:
        return 0


# 4 Complete the HEADER and BODY of this function. (No EXAMPLES.) /2
def print_items(items: str):
    """Print the things in items nicely labelled with index numbers.

    If the list is empty, print 'No items!'.
    """

    if len(items) > 0:
        for i in range(len(items)):
            print("index {}: {}".format(i, items[i]))
    else:
        print("No items!")


# 5 Complete the BODY of this function. (No EXAMPLES.) /1
def print_long_strings(strs: str, minimum: int):
    """Print only the strings in strs that are strictly longer than minimum.

    Print all items on their own line. If there are no strings to print,
    print 'No items!'.
    """

    while True:
        try:
            if len(strs) > 0:
                print("Strings longer than {}:".format(minimum))
                for string in strs:
                    if len(string) > minimum:
                        print(string)
            else:
                print("No items!")
            break
        except:
            print("Invalid input...")


# 6 Complete the DESCRIPTION, EXAMPLES, and BODY of this function. /3
def longest_string(strs: str) -> str:
    """Return the longest string in a list of strings strs, given by the user

    >>> longest_string(["hi", "hello", "bye", "123456"])
    123456
    >>> longest_string(["a", "ab", "abc", "abcd", ""])
    abcd
    """

    if len(strs) > 0:
        longest_word = ""
        for i in range(len(strs)):
            if len(strs[i]) > len(longest_word):
                longest_word = strs[i]
        return longest_word
    else:
        print("No items! Returning an empty string.")
        return ""


# 7 DO NOT ALTER ANY CODE BELOW THIS LINE ---#
def main():
    NUM_STRINGS = 5
    print('Something About Strings\n')
    print('Enter', NUM_STRINGS, 'strings:')
    strings = get_list_of_strings(NUM_STRINGS)
    print('\nYou entered:')
    print_items(strings)
    print()
    cut = get_int('Enter a minimum length: ')
    print_long_strings(strings, cut)
    avg = average_length(strings)
    print('\nThe average length: {:.1f}'.format(avg))
    print('The longest string is:', longest_string(strings))


main()

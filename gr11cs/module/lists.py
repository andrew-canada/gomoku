"""
List algorithms
Description: create lists, get data, and perform operations on lists
"""

__author__ = "Andrew Peng"

n = 10

for i in range(6):
	print(n//(i+1))
	n -=1



# 1
def get_string_list(n):
    strings = []
    for i in range(n):
        string = input()
        strings.append(string)
    return strings


# 2
def get_int_list(n):
    integers = []
    for i in range(n):
        integer = int(input())
        integers.append(integer)
    return integers


# 2
def get_float_list(n):
    floats = []
    for i in range(n):
        num = float(input())
        floats.append(num)
    return floats


# 3
def mean(num_list):
    total = 0
    average = 0
    for num in num_list:
        total += num
    average = total / len(num_list)
    return average


# 4
def lengths_of_strings(string_list):
    lengths = []
    for string in string_list:
        lengths.append(len(string))
    return lengths


# 5
def mean_length_of_strings(string_list):
    lengths = lengths_of_strings(string_list)
    return mean(lengths)


# 6
def count(lst, item):
    occurrences = 0
    for element in lst:
        if element == item:
            occurrences += 1
    return occurrences


# 8
def median(num_list):
    num_list.sort()
    median_length = 0
    length = len(num_list)
    if length % 2 == 0:
        median_length = (num_list[length//2 - 1] + num_list[length//2]) / 2
    else:
        median_length = num_list[length//2]
    return median_length


# 9
def median_length_of_strings(string_list):
    string_list.sort()
    lengths = lengths_of_strings(string_list)
    return median(lengths)


def main():
# 10 
    students = ["Alan T", "Ada L", "Donald K", "Albert E"]
    ids = [110101101, 271828182, 314159265, 299792458]
    print("CLASS LIST\n----------")
    print("{:12} {}".format("Student", "ID"))
    for i in range(len(students)):
        print("{:12} {}".format(students[i], ids[i]))

    name = input("Enter a name: ")
    found = False
    for i in range(len(students)):
        if students[i] == name:
            found = True
            print("{} student id: {}".format(name, ids[i]))
    if found == False:
        print("{} is not a student!".format(name))

    print("---------------------")

# 7
# test index(), pop(), insert(), sort() -> what do they do and when do exceptions occur
    print("index() method")
    print(students.index("Ada L"))
    # print(students.index("Allan T")) -> ValueError exception

    print("pop() method")
    print(students)
    print(students.pop(1))
    print(students)
    # print(students.pop(10)) -> IndexError exception

    print("insert() method")
    print(students.insert(1, "Ada L"))
    print(students)
    print(students.insert(10, "Joe")) 
    print(students)
    print(students.insert(-2, "John")) 
    print(students)

    # function testing
    print("sort() method")
    print(students.sort())
    print(students)

    print("---------------------")
    print("Enter 3 strings: ")
    names = get_string_list(3)
    print(names)

    print("Enter 3 ints: ")
    ages = get_int_list(3)
    print(ages)

    print("Enter 3 floats: ")
    scores = get_float_list(3)
    print(scores)

    print("Mean of int list: ")
    average = mean([1, 2, 3])
    print(average)

    print("List of string lengths: ")
    lengths = lengths_of_strings(["joe", "john"])
    print(lengths)

    print("Mean of string lengths: ")
    average = mean_length_of_strings(["joe", "john"])
    print(average)

    print("Number of occurrences: ")
    occurrences = count([1, 2, 2, 3], 2)
    print(occurrences)

    print("Int list median: ")
    median1 = median([1, 2, 10, 4, 5])
    median2 = median([1, 2, 3, 4])
    print(median1)
    print(median2)

    print("String length list median: ")
    median3 = median_length_of_strings(["a", "ab", "abc", "abcd", "abcde"])
    median4 = median_length_of_strings(["a", "ab", "abc", "abcd"])
    print(median3)
    print(median4)
    

if __name__ == "__main__":
    main()

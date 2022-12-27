"""Lists"""
# Lists
# printing elements in a loop
my_list = ["hello", 5.4, False, 6]

print(my_list)

# for-each loop
# convenient, but no index
for item in my_list:
    print(item)
    if(item == False):
        item == True
print(my_list)

# for loop
# more clunky, but has index and can alter list values
for i in range(len(my_list)):
    print("Item", i, ":", my_list[i])
    if(my_list[i] == False):
        my_list[i] = True
print(my_list)

"""Sorting Lists"""
# Sorting Lists
my_list = [3, 7, 1, 86, 3, 65, 3, 7, 357, 45, 27]
words = ["Abc", "abc", "ZxY"]
mix = ["a", 2]
print(my_list)
print(words)

my_list.sort()
words.sort()
# mix.sort() -> type error
print(my_list)
# prints ["Abc", "ZxY", "abc"]
print(words)

"""Summing Lists"""
# Summing Lists
print(sum(my_list))

# this is an algorithm, a recipe for solving a problem
def my_sum(nums: list) -> float:
    sum = 0
    for num in nums:
        sum += num
    return sum

"""Extreme Values"""
# Extreme Values
print(my_sum(my_list))

def my_max(nums: list):
    maximum = nums[0]
    for i in range(1, len(nums)):
        if nums[i] > maximum:
            maximum = nums[i]
    return maximum

print(max(my_list))
print(my_max(my_list))

def my_min(nums: list):
    minimum = nums[0]
    for i in range(1, len(nums)):
        if nums[i] < minimum:
            minimum = nums[i]
    return minimum

print(min(my_list))
print(my_min(my_list))

"""Searching Lists"""
# Searching Lists
class_list = ["Rogan", "Carole", "Talia", "Carole"]
look_for = "Carole"

def my_search(my_list, look_for):
    for i in range(len(my_list)):
        if my_list[i] == look_for:
            return(i)

index = my_search(class_list, "Carole")
index2 = class_list.index("Carole") # -> error occurs if element isn't found
index3 = None
if class_list.count("Carole") != 0:
    index3 = class_list.index("Carole")
print("Carole's index is {}".format(index))




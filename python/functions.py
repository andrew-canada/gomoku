from datetime import datetime

def print_time():
    print("Task completed")
    print(datetime.now())
    print()

first_name = "Andrew"
print_time()

for x in range (1, 10):
    print(x)

print_time

def print_time(task_name):
    print(task_name)
    print(datetime.now())
    print()

first_name = "Andrew"
print_time("name assigned to andrew")

for x in range(1, 3):
    print(x)
    
print_time("loop ended")

first_name = input("Enter your fist name: ")
first_name_initial = first_name[0:1]

last_name = input("Enter your last name: ")
last_name_initial = last_name[0:1]

print(first_name_initial + last_name_initial)

def get_initial (name):
    #initial = name[ :1]
    #return initial
    return name[ :1]

first_name = input("Enter your fist name: ")
first_name_initial = get_initial(first_name)

last_name = input("Enter your last name: ")
last_name_initial = get_initial(last_name)

print(first_name_initial + last_name_initial)

print("Your initials are " + get_initial(first_name) + get_initial(last_name))

def get_initial(name, force_uppercase=True):

    if force_uppercase:
        initial = name[0:1].upper()
    else:
        initial = name[0:1]
    
    return initial

print(get_initial("andrew", False))
print(get_initial(force_uppercase=True, name="andrew"))
if get_initial("andrew", False) == "A":
    print("doesn't works")
else:
    print("work")    


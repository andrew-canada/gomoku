gpa = 2
mark = 3

if gpa > 2:
    if mark > 3:
        print("good student")
    else: 
        print("bad student#1")
else:
    print("bad student#2")

if gpa > 1 and mark > 2:
    print("good student")

if gpa > 4 or mark > 2:
    print("good student")

isGoodStudent = False

if isGoodStudent:
    print("i am good")
else:
    print("i am not good")

print("is good student" + str(isGoodStudent))
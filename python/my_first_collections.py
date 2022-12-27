from array import array

names = ("a", "b")
marks = []
marks.append(67)
marks.append(88)
print(names)
print(marks[1])
marks.insert(1, 94)
print(marks)
marks.sort()
print(marks)
marks.sort(reverse=True)
print(marks)

myArray = array('L')
myArray.append(45)
myArray.append(5)
print(myArray[0]+myArray[1])

names = ["bob", "joe", "chris", "bill", "justin"]
presentors = names [1:3]
print(presentors)

person = {"first" : "andrew"}
person ["last"] = "number 1"
print(person)
print(person ["last"])


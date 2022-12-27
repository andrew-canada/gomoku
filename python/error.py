x = 376
y = 30
z = 0
if x == y:
    print("success")
else:
    print("not equal")    

try:
    print(x/z)
except ZeroDivisionError as e:
    print(e)
finally:
    print("hello")

a = 673.2
b = 0

print(a + b)

if b > a:
    print("b is greater than a")
else: 
    print("a is greater than b")

try:
    print(b/a)
except TypeError as e:
    print("b/a=" + str(b) + "/" + str(a) + " | error is: " + str(e))
finally:
    print("b/a=" + str(b) + "/" + str(a))

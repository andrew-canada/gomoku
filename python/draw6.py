from matplotlib.pyplot import *
from numpy import *
n = eval(input('enter the no. of sides greater than 2: '))
t = arange(0,360+(360/(n)),360/(n))
#t = arange(0,360,360/n)
x = 10*sin(radians(t))
y=10*cos(radians(t))
plot(x,y)
axis('equal')

show()
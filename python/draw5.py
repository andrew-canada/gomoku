import turtle
# Set up the new blank window
window=turtle.Screen()
# Set the fill back ground color
turtle.bgcolor("yellow")
# Set the fill color for the triangle
turtle.fillcolor("red")
turtle.begin_fill()
turtle.pendown()

# draw the 3 sides of triangle
for i in range(3):
    turtle.forward(200)
    turtle.left(120)
    turtle.hideturtle()
turtle.end_fill()

window.exitonclick()
from datetime import date

day = date(2010, 8, 9)
t=date.today()
print(day.strftime("%A"))
print("{} days elapsed".format((t-day).days))
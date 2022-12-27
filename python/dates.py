from datetime import datetime, timedelta

now = datetime.now()
print("current time is: " + str(now))
today = datetime.now()
print("today is " + str(today))

one_day = timedelta(days=1)
yesterday = now - one_day
print("Yesterday was: " + str(yesterday))
today = datetime.now().day
month = datetime.now().month
year = datetime.now().year
print("Today is {2} {1} {0}". format (str(year), str(month), str(today)))
birthday = input("When is your birthday (dd/mm/yyyy)? ")
birth_date = datetime.strptime(birthday, "%d/%m/%Y")
print("Your birthday is: " + str(birth_date))
one_day = timedelta (days=1)
year_day = timedelta (days=365)
one_week = timedelta (days=54)
print(one_day + yesterday + one_week)
today = datetime.now()
some_days_ago = today - one_day - year_day - one_week
print("One year and 55 days ago, it is " + str(some_days_ago))
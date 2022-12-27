country = input("Are you from Canada? Yes/No: ")
print(country)

if country.lower() == "yes":
    province = input("Which province do you come from? Ontario, Alberta, Quebec, Yukon, Other: ")
    print(province)
    print(province.lower())
    
    if province.lower() == "ontario":
        tax = 0.13
        print(tax)
    elif province.lower() in("alberta", "quebec", "yukon"):
        tax = 0.05
        print("The tax for " + province.lower() + " is " + str(tax*100) + "%")
else:
    tax = 0
    print("The tax for non-Canadians is $" + str(tax))

price = input("How much is your purchase? ")
print(float(price) * (1 + tax))
print("{:.2f}".format(float(price) * (1 + tax)))
print("{:.2f}".format(round(float(price) * (1 + tax), 2)))

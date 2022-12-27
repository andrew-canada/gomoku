temp = float(input("What is the temperature (in degrees celcius)? "))
moisture = float(input("What's the weather? Pick the corresponding number:\n 1. Sunny\n 2. Overcast\n 3. Rainy\n 4. Snowy\n"))

if temp > 0 and moisture == 4:
    print("Invalid input")
    exit()

occasion = int(input("Where are you going? Pick the corresponding number:\n 1. School\n 2. Da Club\n 3. Joel's Birthday Party\n"))

print("Today you should wear ", end="")

if temp < 0:
    print("boots and a warm coat, along with ", end="")
    #sunny
    if moisture == 1 and occasion == 1:
        print("a hat, and a backpack")
    elif moisture == 1 and occasion == 2:
        print("a hat, and a trendy coat")
    elif moisture == 1:
        print("a hat, and a tux or fancy dress")
    
    #overcast
    if moisture == 2 and occasion == 1:
        print("a backpack")
    elif moisture == 2 and occasion == 2:
        print("a trendy coat")
    elif moisture == 2:
        print("a tux or fancy dress")

    #rainy
    if moisture == 3 and occasion == 1:
        print("a rain coat, and a backpack")
    elif moisture == 3 and occasion == 2:
        print("a rain coat, and a trendy coat")
    elif moisture == 3:
        print("a rain coat, and a tux or fancy dress")

    #snowy
    if moisture == 4 and occasion == 1:
        print("a waterproof jacket, and a backpack")
    elif moisture == 4 and occasion == 2:
        print("a waterproof jacket, and a trendy coat")
    elif moisture == 4:
        print("a waterproof jacket, and a tux or fancy dress")

elif 0 <= temp <= 15:
    #sunny
    if moisture == 1 and occasion == 1:
        print("shoes, a hat, and a backpack")
    elif moisture == 1 and occasion == 2:
        print("shoes, a hat, and a trendy coat")
    elif moisture == 1:
        print("shoes, a hat, and a tux or fancy dress")
    
    #overcast
    if moisture == 2 and occasion == 1:
        print("shoes, any clothing, and a backpack")
    elif moisture == 2 and occasion == 2:
        print("shoes, any clothing, and a trendy coat")
    elif moisture == 2:
        print("shoes, any clothing, and a tux or fancy dress")

    #rainy
    if moisture == 3 and occasion == 1:
        print("rain boots, a rain coat, and a backpack")
    elif moisture == 3 and occasion == 2:
        print("rain boots, a rain coat, and a trendy coat")
    elif moisture == 3:
        print("rain boots, a rain coat, and a tux or fancy dress")
    
else:
    #sunny
    if moisture == 1 and occasion == 1:
        print("sandals, a hat, and a backpack")
    elif moisture == 1 and occasion == 2:
        print("sandals, a hat, and a trendy coat")
    elif moisture == 1:
        print("sandals, a hat, and a tux or fancy dress")
    
    #overcast
    if moisture == 2 and occasion == 1:
        print("sandals, any clothing, and a backpack")
    elif moisture == 2 and occasion == 2:
        print("sandals, any clothing, and a trendy coat")
    elif moisture == 2:
        print("sandals, any clothing, and a tux or fancy dress")

    #rainy
    if moisture == 3 and occasion == 1:
        print("rain boots, an umbrella, and a backpack")
    elif moisture == 3 and occasion == 2:
        print("rain boots, an umbrella, and a trendy coat")
    elif moisture == 3:
        print("rain boots, an umbrella, and a tux or fancy dress")

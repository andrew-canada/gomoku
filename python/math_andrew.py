def add_numbers(number_1, number_2):
    
    if number_1 in range(1, 4):
        addition = number_1 + number_1
    else:
        addition = number_1 + number_2

    return addition

print(add_numbers(3, 5))
    

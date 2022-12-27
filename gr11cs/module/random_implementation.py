def random(x):
    new_x = (x + 37) % 100
    return new_x

def main():
    x = int(input("Please seed me: "))
    for i in range(30):
        x = random(x)
        print("Random Number", x // 10)

main()
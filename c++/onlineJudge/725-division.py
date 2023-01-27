def main():
    first = True
    f = int(input())
    while (f != 0):
        if (not first):
            print()
        first = False

        noSol = True

        for fghij in range(1234, 98765//f+1):
            abcde = fghij*f
            positions = fghij < 10000

            tmp = fghij
            while (tmp):
                positions |= (1 << (tmp % 10))
                tmp //= 10
            tmp = abcde
            while (tmp):
                positions |= (1 << (tmp % 10))
                tmp //= 10

            if positions == (1 << 10)-1:
                print("{:05} / {:05} = {}".format(abcde, fghij, f))
                noSol = False

        if noSol:
            print(f"There are no solutions for {f}.")

        f = int(input())


main()

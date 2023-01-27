def main():
    first = True
    numSet = input().split()
    size = int(numSet[0])
    while (size):
        if not first:
            print()
        first = False

        for a in range(1, size-4):
            for b in range(a+1, size-3):
                for c in range(b+1, size-2):
                    for d in range(c+1, size-1):
                        for e in range(d+1, size):
                            for f in range(e+1, size+1):
                                print(
                                    f"{numSet[a]} {numSet[b]} {numSet[c]} {numSet[d]} {numSet[e]} {numSet[f]}")
        numSet = input().split()
        size = int(numSet[0])


main()

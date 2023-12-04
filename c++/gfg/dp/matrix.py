from functools import cache

def matrixChainOrder(dims: list[int]) -> int:
    @cache
    def a(i, j):
        return min((a(i, k) + dims[i] * dims[k] * dims[j] + a(k, j) 
                   for k in range(i + 1, j)), default=0)

    return a(0, len(dims) - 1)

print(matrixChainOrder([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]))
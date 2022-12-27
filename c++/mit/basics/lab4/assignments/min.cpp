#include <iostream>

#define macroMin(n1, n2) ((n1 < n2) ? n1 : n2)

template <typename T>
T min(T n1, T n2)
{
    return (n1 < n2) ? n1 : n2;
}

int main()
{
    std::cout << min(9, 10) << std::endl;
    std::cout << macroMin(3, 4);
}
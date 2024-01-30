#include <iostream>
#include <cmath>

double gaussian_round(double num, int decimals)
{
    double factor = std::pow(10.0, decimals);
    double n2 = num * (factor * 10);
    n2 = floor(n2);
    n2 /= 10;
    num *= factor;
    if (std::floor(num) + 0.5 == n2 && static_cast<int>(num) % 2 == 0)
    {
        num = std::floor(num);
    }
    else
    {
        num = std::round(num);
    }
    return num / factor;
}

int main()
{
    double num = 1.1234858758765;
    num = gaussian_round(num, 5);
    std::cout << num << std::endl;
    return 0;
}
#include <iostream>
#include <cstdio>
#include <iomanip>

int main()
{
    double myDouble = 33333333333333.111;
    printf("The value of myDouble with 2 decimal places is: %.2f\n", myDouble);

    myDouble = 33333333333333.111;
    std::cout << std::fixed << std::setprecision(2) << "The value of myDouble with 2 decimal places is: " << myDouble << std::endl;
    return 0;
}

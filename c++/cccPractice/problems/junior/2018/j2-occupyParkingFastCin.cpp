#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int numCars;
    int occupied = 0;
    char day2Car;

    std::cin >> numCars;

    char *day1 = new char[numCars];

    for (int i = 0; i < numCars; i++)
    {
        std::cin >> day1[i];
    }

    for (int i = 0; i < numCars; i++)
    {
        std::cin >> day2Car;

        if (day1[i] == day2Car && day1[i] == 'C')
        {
            occupied += 1;
        }
    }

    std::cout << occupied;
}
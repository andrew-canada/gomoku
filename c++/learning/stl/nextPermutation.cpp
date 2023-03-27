#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    // same result with {3, 2, 1}
    std::vector<int> v = {1, 1, 1};
    std::next_permutation(v.begin(), v.end());
    for (int x : v)
    {
        std::cout << x << " ";
    }
    // do
    // {
    //     for (int x : v)
    //     {
    //         std::cout << x << " ";
    //     }
    //     std::cout << std::endl;
    // } while (std::next_permutation(v.begin(), v.end()));

    // return 0;
}

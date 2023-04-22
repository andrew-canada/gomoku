#include <stdio.h>
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

#define ALL(v) v.begin(), v.end()

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 10000);

    vector<int> numbers(1000000);
    generate(numbers.begin(), numbers.end(), [&]()
             { return dist(gen); });

    sort(ALL(numbers));

    printf("%d", binary_search(ALL(numbers), 5));
    printf("%d", binary_search(ALL(numbers), 101));
    printf("%d", binary_search(ALL(numbers), 0));
}
#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> myMap = {
        {"one", 1},
        {"two", 2},
        {"three", 3}};

    // Test if "one" exists in the map
    if (myMap.find("one") != myMap.end())
    {
        std::cout << "Key 'one' found with value " << myMap["one"] << std::endl;
    }
    else
    {
        std::cout << "Key 'one' not found in the map" << std::endl;
    }

    // Test if "four" exists in the map
    if (myMap.find("four") != myMap.end())
    {
        std::cout << "Key 'four' found with value " << myMap["four"] << std::endl;
    }
    else
    {
        std::cout << "Key 'four' not found in the map" << std::endl;
    }

    return 0;
}

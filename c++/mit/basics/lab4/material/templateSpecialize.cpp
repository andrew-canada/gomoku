#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
class Color
{
private:
    T colorCode;

public:
    Color(T colorCode)
    {
        this->colorCode = colorCode;
    }
    // math only works when colorCode is a number
    T changeShade(int codeDifference)
    {
        return (colorCode + codeDifference);
    }
};

// when colorCode is a string instead of number
template <>
class Color<string>
{
private:
    string colorCode;

public:
    Color(string colorCode) : colorCode(colorCode) {}
    string lowercase()
    {
        // starting point, ending point, destination, function
        // tolower needs double colon to know origin of algorithm
        transform(colorCode.begin(), colorCode.end(), colorCode.begin(), ::tolower);
        return colorCode;
    }
};

int main()
{
    Color<int> intCode(255);
    cout << intCode.changeShade(10) << endl;
    Color<string> strCode("BdGa");
    cout << strCode.lowercase() << endl;
}
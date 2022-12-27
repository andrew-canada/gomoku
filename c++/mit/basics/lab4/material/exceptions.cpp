#include <iostream>
#include <stdexcept>

using namespace std;

int divide(int dividend, int divisor)
{
    if (divisor == 0)
    {
        throw std::runtime_error("divide by 0");
    }
    return dividend / divisor;
}

void useDivide(int num, int quotient)
{
    try
    {
        quotient = divide(num, 0);
    }
    // tries to catch error inside try block
    // always use references when specifying catch block (prevents excessive copying, allows for virtual functions)
    catch (runtime_error &error)
    {
        // error.what() returns the error description
        cerr << "error: " << error.what() << endl;
    }
}

int main()
{
    useDivide(8, 45);
}
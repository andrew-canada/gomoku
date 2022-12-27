#include <iostream>
#include <string>

using namespace std;

class Money
{
private:
    int dollars, cents;

public:
    Money() : dollars(0), cents(0){};
    Money(int dollars, int cents)
    {
        this->dollars = dollars;
        this->cents = cents;
    }
    string getValue()
    {
        return "$" + to_string(this->dollars + this->cents / 100.0);
    }
    Money operator+(Money firstAmount)
    {
        Money tempAmount;
        tempAmount.dollars = firstAmount.dollars + dollars;
        tempAmount.cents = firstAmount.cents + cents;
        if (tempAmount.cents >= 100)
        {
            tempAmount.dollars += 1;
            tempAmount.cents -= 100;
        }
        return tempAmount;
    }
};

int main()
{
    Money amt1(2, 55);
    Money amt2(1, 50);
    Money sum1 = amt1 + amt2;
    cout << sum1.getValue() << endl;
}
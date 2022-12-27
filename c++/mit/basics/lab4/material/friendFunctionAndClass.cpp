#include <iostream>
#include <string>

using namespace std;

class friendMoney
{
private:
    friend friendMoney operator+(friendMoney firstAmount, friendMoney secondAmount);
    int dollars, cents;

public:
    friendMoney() : dollars(0), cents(0){};
    friendMoney(int dollars, int cents)
    {
        this->dollars = dollars;
        this->cents = cents;
    }
    string getValue()
    {
        return "$" + to_string(this->dollars + this->cents / 100.0);
    }
};

friendMoney operator+(friendMoney firstAmount, friendMoney secondAmount)
{
    friendMoney tempAmount;
    tempAmount.dollars = firstAmount.dollars + secondAmount.dollars;
    tempAmount.cents = firstAmount.cents + secondAmount.cents;
    if (tempAmount.cents >= 100)
    {
        tempAmount.dollars += 1;
        tempAmount.cents -= 100;
    }
    return tempAmount;
}

int main()
{
    friendMoney amt1(2, 55);
    friendMoney amt2(1, 50);
    friendMoney sum1 = amt1 + amt2;
    cout << sum1.getValue();
}
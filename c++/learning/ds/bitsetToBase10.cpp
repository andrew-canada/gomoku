#include <bitset>
#include <iostream>

int main()
{
    std::bitset<4> bits("1010");
    unsigned long num = bits.to_ulong();
    std::cout << "Base-10 number: " << num << std::endl;
    return 0;
}

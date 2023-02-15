#include <bitset>
#include <iostream>

int main()
{
    std::bitset<8> bits("11111111");
    std::cout << "Original bitset: " << bits << std::endl;
    bits = bits.to_ulong() + 1;
    std::cout << "New value: " << bits << std::endl;
    return 0;
}

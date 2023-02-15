#include <bitset>
#include <iostream>

int main()
{
    std::bitset<8> bits("10101010");
    std::cout << "Original bitset: " << bits << std::endl;
    bits = bits << 4;
    std::cout << "Shifted bitset: " << bits << std::endl;
    bits = bits >> 4;
    std::cout << "Shifted bitset: " << bits << std::endl;
    return 0;
}

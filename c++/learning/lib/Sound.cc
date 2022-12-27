#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    //PlaySound(TEXT("C:\\work\\projects\\andrew-c++\\learning\\lib\\big_pig_snort.wav"), 0, 0);
    //PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS);
    PlaySound(TEXT("recycle.wav"), NULL, SND_FILENAME);
    cin.ignore();
    return 0;
}
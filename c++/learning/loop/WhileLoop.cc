#include <iostream>
using namespace std;

void whileLoop()
{
	int x = 100;
	while (x <= 500)
	{
		if (x % 3 == 0 && x % 5 == 0 && x % 7 == 0)
		{
			cout << x << " ";
		}
		x++;
	}
}

int main()
{
    whileLoop();
    return 0;
}

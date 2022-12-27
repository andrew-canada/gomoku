#include <iostream>
using namespace std;

template <class T>

T sum (T a, T b)
{
	return a + b;
}
template <class T, class U>
U sum (T a, U b)
{
	return a + b;
}

int main()
{
	cout << sum(1, 2) << endl;
	cout << sum(1.4, 2.1) << endl;
	cout << sum(1, 2.8);
	return 0;
}

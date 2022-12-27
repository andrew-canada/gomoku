#include<iostream> 
using namespace std;

void logic()
{
    int number;
    cout << "Please enter a whole number: ";
    cin >> number;
    if (number % 2 == 0)
    {
        cout << "Even" << endl;
    }
    else
    {
        cout << "Odd" << endl;
    }
    float s1, s2, s3;
    cout << "Please enter 3 triangle side lengths: ";
    cin >> s1 >> s2 >> s3;
    cout << s1 << " " << s2 << " " << s3 << endl;
    if (s1 == s2 && s2 == s3)
    {
        cout << "Equilateral" << endl;
    }
    else if (s1 != s2 && s1 != s3 && s2 != s3)
    {
        cout << "Scalene" << endl;
    }
    else
    {
        cout << "Isosceles" << endl;
    }
}

int main()
{
    logic();
    return 0;
}

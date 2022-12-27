#include <iostream>
#include "vector.h"

using namespace std;

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Point::offset(double x, double y)
{
    this->x += x;
    this->y += y;
}

void Point::print()
{
    cout << "(" << x << ", " << y << ")";
}

void Vector::print()
{
    startPoint.print();
    cout << " -> ";
    endPoint.print();
    cout << endl;
}

int main()
{
    Point p1;
    Point p2(1, 2);
    Vector v1(p1, p2);
    v1.print();
    v1.offset(1, 2);
    v1.print();
}
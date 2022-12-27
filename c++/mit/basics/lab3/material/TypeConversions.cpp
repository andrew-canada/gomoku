#include <iostream>

using namespace std;

class Coordinate
{
public:
    double xVal;
    Coordinate(double xVal)
    {
        this->xVal = xVal;
    }
};

class Point
{
public:
    double c1;
    double c2;
    Point(Coordinate c1, Coordinate c2)
    {
        this->c1 = c1.xVal;
        this->c2 = c2.xVal;
    }
    void print()
    {
        cout << c1 << "," << c2 << endl;
    }
};

void printCoordinate(Coordinate c)
{
    cout << "xVal: " << c.xVal << endl;
}

int main()
{
    // because Coordinate takes a double and function takes a Coordinate,
    // the compiler will convert this satemement into :
    // printCoordinate(Coordinate(2.2));
    printCoordinate(2.2);

    // like a function, constructor can also convert types
    // Point takes Coordinate and Coordinate takes double, so conversion occurs
    Point p1(1.1, 2.2);
    p1.print();
    Point p2(1, 2);
    p2.print();
}
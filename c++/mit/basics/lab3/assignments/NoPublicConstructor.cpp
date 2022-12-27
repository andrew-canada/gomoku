#include <iostream>

using namespace std;

class Point
{
private:
    double x;
    double y;
    Point(double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
    }

public:
    static Point getInstance(double x, double y)
    {
        return Point(x, y);
    }
    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
    void setX(const double new_x)
    {
        this->x = new_x;
    }
    void setY(const double new_y)
    {
        this->y = new_y;
    }
};

int main()
{

    Point p = Point::getInstance(1, 1);
    cout << p.getX();
}
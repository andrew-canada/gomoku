class Point
{
public:
    double x, y;
    Point();
    Point(double x, double y);
    void offset(double x, double y);
    void print();
};

class Vector
{
public:
    Point startPoint, endPoint;
    Vector()
    {
        Point startPoint;
        Point endPoint;
    }
    Vector(Point startPoint, Point endPoint)
    {
        this->startPoint = startPoint;
        this->endPoint = endPoint;
    }
    void offset(double x, double y)
    {
        startPoint.offset(x, y);
        endPoint.offset(x, y);
    }
    void print();
};
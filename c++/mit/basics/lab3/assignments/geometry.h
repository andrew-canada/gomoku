#include <iostream>

class Point
{
private:
    double x;
    double y;

public:
    Point(double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
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

class PointArray
{
private:
    int size;
    Point *points;

public:
    PointArray();
    PointArray(const Point points[], const int size);
    PointArray(const PointArray &pv);
    ~PointArray();
    void resize(int n);
    void push_back(const Point &p);
    void insert(const int position, const Point &p);
    void remove(const int pos);
    const int getSize() const;
    void clear();
    Point *get(const int position);
    const Point *get(const int position) const;
};

class Polygon
{
protected:
    PointArray pointArr;
    static int numberOfPolygons;

public:
    Polygon(Point arrOfPoints[], int length) : pointArr(arrOfPoints, length)
    {
        // this->pointArr = PointArray(arrOfPoints, length);
        numberOfPolygons += 1;
        std::cout << "numberOfPolygons" << this->numberOfPolygons << std::endl;
    };
    Polygon(const PointArray &existingPointArr) : pointArr(existingPointArr)
    {
        this->numberOfPolygons += 1;
    };
    virtual double findArea() = 0;
    static int getNumPolygons()
    {
        return numberOfPolygons;
    }
    int getNumSides() const
    {
        return pointArr.getSize();
    }
    const PointArray *getPoints() const
    {
        return &pointArr;
    }
};

class Rectangle : public Polygon
{
protected:
    static int numberOfPolygons;

public:
    Rectangle(Point arrOfPoints[], int length) : Polygon(arrOfPoints, length){};
    Rectangle(const Point &lowerLeft, const Point &upperRight);
    Rectangle(int lowerLeftX, int lowerLeftY, int upperRightX, int upperRightY);
    double findArea();
};

class Triangle : public Polygon
{
protected:
    static int numberOfPolygons;

public:
    Triangle(const Point &p1, const Point &p2, const Point &p3);
    double findArea();
};

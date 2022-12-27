#include <iostream>
#include <math.h>
#include "geometry.h"

using namespace std;

double *getSideLengths(const PointArray &points, int numberOfPoints)
{
    double xDist;
    double yDist;
    double *sideLengths = new double[numberOfPoints];
    for (int i = 0; i < numberOfPoints; i++)
    {
        int j = i + 1;

        if (j == numberOfPoints)
        {
            xDist = abs(points.get(i)->getX() - points.get(0)->getX());
            yDist = abs(points.get(i)->getY() - points.get(0)->getX());
        }
        else
        {
            xDist = abs(points.get(i)->getX() - points.get(j)->getX());
            yDist = abs(points.get(i)->getY() - points.get(j)->getX());
        }
        sideLengths[i] = sqrt(xDist * xDist + yDist * yDist);
    }
    return sideLengths;
}

void printAttributes(Polygon *inputPolygon)
{
    cout << "area: " << inputPolygon->findArea() << endl;
    const PointArray *polygonPoints = inputPolygon->getPoints();
    for (int i = 0; i < polygonPoints->getSize(); i++)
    {
        cout << "(" << polygonPoints->get(i)->getX() << ", " << polygonPoints->get(i)->getY() << ")" << endl;
    }
}

PointArray::PointArray()
{
    size = 0;
    points = new Point[size];
}

PointArray::PointArray(const Point points[], const int size)
{
    this->size = size;
    this->points = new Point[size];
    for (int i = 0; i < size; i++)
    {
        this->points[i] = points[i];
    }
}

PointArray::PointArray(const PointArray &pv)
{
    size = pv.size;
    points = new Point[size];
    for (int i = 0; i < size; i++)
    {
        points[i] = pv.points[i];
    }
}

PointArray::~PointArray()
{
    delete[] points;
}

void PointArray::resize(int n)
{
    Point *newArr = new Point[n];
    int minElements = (n > size ? n : size);
    for (int i = 0; i < minElements; i++)
    {
        newArr[i] = points[i];
    }
    delete[] points;
    size = n;
    points = newArr;
}

void PointArray::push_back(const Point &p)
{
    resize(size + 1);
    points[size - 1] = p;
}

void PointArray::insert(const int position, const Point &p)
{
    resize(size + 1);
    for (int i = size - 1; i > position; i--)
    {
        points[i] = points[i - 1];
    }

    points[position] = p;
}

void PointArray::remove(const int pos)
{
    for (int i = pos; i < size - 1; i++)
    {
        points[i] = points[i + 1];
    }

    resize(size - 1);
}

const int PointArray::getSize() const
{
    return size;
}

void PointArray::clear()
{
    resize(0);
}

Point *PointArray::get(const int position)
{
    // return (position <= 0 && position < size) ? points + position : NULL;
    if (position >= 0 && position < size)
    {
        return (points + position);
    }
    else
    {
        return NULL;
    }
}

const Point *PointArray::get(const int position) const
{
    return (position >= 0 && position < size) ? points + position : NULL;
}

Point constructorPoints[4];
Point *updateConstructorPoints(const Point &p1, const Point &p2, const Point &p3, const Point &p4 = Point(0, 0))
{
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    return constructorPoints;
}

int Polygon::numberOfPolygons = 0;
int Rectangle::numberOfPolygons = 0;

Rectangle::Rectangle(const Point &lowerLeft, const Point &upperRight)
    : Polygon(updateConstructorPoints(lowerLeft, Point(lowerLeft.getX(), upperRight.getY()), upperRight, Point(upperRight.getX(), lowerLeft.getY())), 4){};

Rectangle::Rectangle(int lowerLeftX, int lowerLeftY, int upperRightX, int upperRightY)
    : Polygon(updateConstructorPoints(Point(lowerLeftX, lowerLeftY), Point(lowerLeftX, upperRightY), Point(upperRightX, lowerLeftY), Point(upperRightX, upperRightY)), 4){};

double Rectangle::findArea()
{

    double length = pointArr.get(2)->getX() - pointArr.get(0)->getX();
    double width = pointArr.get(1)->getY() - pointArr.get(0)->getY();
    return std::abs(length * width);
}

int Triangle::numberOfPolygons = 0;

Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3)
    : Polygon(updateConstructorPoints(p1, p2, p3), 3){};

double Triangle::findArea()
{
    double *sideLengths = getSideLengths(pointArr, 3);
    double a = sideLengths[0];
    cout << "a: " << a << endl;
    double b = sideLengths[1];
    cout << "b: " << b << endl;
    double c = sideLengths[2];
    cout << "c: " << c << endl;
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
    Point p1(1.1, 1);
    Point p2(2.9, 2);
    Point p3(1, 3);
    Point p4(1, 4);
    Point p5(1, 5);

    Point *array1 = new Point[5];
    array1[0] = p1;
    array1[1] = p2;
    array1[2] = p3;
    array1[3] = p4;
    array1[4] = p5;

    // PointArray pointArr(array1, 5);
    // Point *array2 = new Point[2];
    // PointArray pointsWithArgs(array2, 3);
    // PointArray copiedArr(pointsWithArgs);
    // PointArray *allocatedPts = new PointArray;
    // delete allocatedPts;
    // Point endpoint(1, 2);
    // Point insertPoint(2, 3);

    // pointArr.resize(8);

    // pointArr.push_back(endpoint);
    // pointArr.insert(4, insertPoint);
    // pointArr.remove(1);
    // cout << pointArr.getSize() << endl;
    // cout << pointArr.get(3) << endl;
    // Point *test = pointArr.get(2);
    // cout << "(" << test->getX() << ", " << test->getY() << ")" << endl;
    // pointArr.clear();

    Rectangle rectangle1(array1, 5);
    Rectangle rectangle2(array1, 5);
    Rectangle rectangle3(array1, 5);
    //  Polygon polygon2(pointArr);
    cout << Rectangle::getNumPolygons() << endl;
    cout << rectangle1.getNumSides() << endl;
    cout << rectangle1.getPoints() << endl;
    const Point *pointTest = rectangle1.getPoints()->get(2);
    cout << pointTest->getX() << endl;
    // int pointTestX = pointTest->getX();
    // cout << pointTestX;

    Rectangle r1(p1, p2);
    const Point *checkP1 = r1.getPoints()->get(0);
    cout << "point 1 : "
         << "(" << checkP1->getX() << ", " << checkP1->getY() << ")" << endl;
    checkP1 = r1.getPoints()->get(1);
    cout << "point 2 x: " << checkP1->getX() << endl;
    cout << "point 2 y: " << checkP1->getY() << endl;
    checkP1 = r1.getPoints()->get(2);
    cout << "point 3 x: " << checkP1->getX() << endl;
    cout << "point 3 y: " << checkP1->getY() << endl;
    checkP1 = r1.getPoints()->get(3);
    cout << "point 4 x: " << checkP1->getX() << endl;
    cout << "point 4 y: " << checkP1->getY() << endl;
    cout << r1.findArea() << endl;

    cout << "triangles" << endl;

    Triangle t(p1, p2, p3);
    cout << "finding area: " << endl;
    cout << t.findArea() << endl;
    cout << "found area" << endl;

    // 5.7 polygon attributes
    double lowerLeftX, lowerLeftY, upperRightX, upperRightY;
    cout << "give rectangle lower left and upper right coordinates: " << endl;
    cin >> lowerLeftX >> lowerLeftY >> upperRightX >> upperRightY;
    Point lowerLeft(lowerLeftX, lowerLeftY);
    Point upperRight(upperRightX, upperRightY);
    Rectangle rect1(lowerLeft, upperRight);
    cout << "rectangle info: " << endl;
    printAttributes(&rect1);
    cout << endl;

    double p1x, p1y, p2x, p2y, p3x, p3y;
    cout << "give 3 triangle coordinates: " << endl;
    cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
    Point pt1(p1x, p1y);
    Point pt2(p2x, p2y);
    Point pt3(p3x, p3y);
    Triangle t1(pt1, pt2, pt3);
    cout << "triangle info: " << endl;
    printAttributes(&t1);
    cout << endl;
}
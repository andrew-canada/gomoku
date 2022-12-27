#include <iostream>

using namespace std;

class Vector
{
public:
    double xStart;
    double xEnd;
    double yStart;
    double yEnd;
};

class Point
{
public:
    double x, y;
};

class OOVector
{
public:
    Point start, end;
};

class MITStudent
{
public:
    char *name;
    int studentID;
};

void offsetVector(OOVector &inVector, double offsetX, double offsetY)
{
    inVector.start.x += offsetX;
    inVector.start.y += offsetY;
    inVector.end.x += offsetX;
    inVector.end.y += offsetY;
}

void printVector(const OOVector &inVector)
{
    cout << "(" << inVector.start.x << "," << inVector.start.y << ") -> ("
         << inVector.end.x << "," << inVector.end.y << ")" << endl;
}

int main()
{
    MITStudent student1;
    MITStudent student2;

    cout << student1.name << endl; // doesn't work because doesn't point to anything
    cout << student1.studentID << endl;
    student1.name = "John Smith";
    cout << student1.name << endl;

    OOVector vector1;
    printVector(vector1);
    vector1.start.x = 1.2;
    vector1.start.y = 0.4;
    vector1.end.x = 2.0;
    vector1.end.y = 1.6;
    printVector(vector1);
    offsetVector(vector1, 1.0, 1.5);
    printVector(vector1);

    OOVector vector2;
    vector2.start = vector1.start; // copies start field values
    printVector(vector2);

    OOVector vector3;
    vector3 = vector1;
    printVector(vector3);
    vector3.start.x = 0;
    printVector(vector3);
    printVector(vector1);
}
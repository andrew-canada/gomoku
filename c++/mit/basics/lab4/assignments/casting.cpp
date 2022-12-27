#include <iostream>

using namespace std;

class Polygon
{
public:
    virtual void printCode();
    void print() const
    {
        cout << "polygon" << endl;
    }
};

class Rectangle : public Polygon
{
public:
    void printCode()
    {
        cout << 2 << endl;
    }
    void print() const
    {
        cout << "rectangle" << endl;
    }
};

class Triangle : public Polygon
{
public:
    void printCode()
    {
        cout << 3 << endl;
    }
    void print() const
    {
        cout << "triangle" << endl;
    }
};

class Rhombus : public Polygon
{
public:
    void printCode()
    {
        cout << 4 << endl;
    }
    void print() const
    {
        cout << "rhombus" << endl;
    }
};

int main()
{
    Triangle t1;
    Polygon *pptr = &t1;
    Triangle *tptr = dynamic_cast<Triangle *>(pptr);
    t1.print();
    tptr->print();

    Rectangle *rect;
    // doesn't work because incompatible types
    // Triangle *tptr1 = dynamic_cast<Triangle *>(rect);
    // Triangle *tptr1 = static_cast<Triangle *>(rect);
    // works because no actual casting, just reinterpreting
    Triangle *tptr1 = reinterpret_cast<Triangle *>(rect);
    rect->print();
    tptr1->print();
}
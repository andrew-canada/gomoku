#include <iostream>

using namespace std;

template <typename T>
class Person
{
private:
    T age;
    int id;

public:
    Person(int id, const T inputAge = 0)
        : age(inputAge)
    {
        this->id = id;
    }
    T getAge() const
    {
        return age;
    }
    int getId() const
    {
        return id;
    }
};

int main()
{
    Person<int> p1(123, 2);
    cout << p1.getAge() << endl;
    cout << p1.getId() << endl;
}
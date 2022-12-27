#include <iostream>
#include <string.h>

using namespace std;

class Student
{
private:
    string name;
    int studentId;

public:
    Student()
    {
        name = "";
        studentId = 0;
    }
    Student(Student &originalStudent)
    {
        this->name = originalStudent.name;
        this->studentId = originalStudent.studentId;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setId(int studentId)
    {
        this->studentId = studentId;
    }
    string getName()
    {
        return name;
    }
    int getId()
    {
        return studentId;
    }
    void printInfo()
    {
        cout << studentId << ": " << name << endl;
    }
};

int main()
{
    Student student1;
    student1.printInfo();
    student1.setName("John Smith");
    student1.setId(123);
    student1.printInfo();
    Student student2 = student1;
    student2.printInfo();
    student1.setId(321);
    student1.setName("abc");
    student1.printInfo();
    student2.printInfo();
}
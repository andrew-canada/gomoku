#include <iostream>
#include <list>
using namespace std;

class School
{
private:
	string schoolName;
	list<string> students;
	list<string> teachers;

public:
	School(string schoolName)
	{
		this->schoolName = schoolName;
	}
	void getInfo()
	{
		cout << "School name: " << schoolName << endl;
		cout << "List of students: ";
		for (string studentName : students)
		{
			cout << studentName << " ";
		}

		cout << endl
			 << "List of teachers: ";
		for (string teacherName : teachers)
		{
			cout << teacherName << " ";
		}
	};
	list<string> getStudentList()
	{
		return students;
	}
	void addStudent(string studentName)
	{
		students.push_back(studentName);
	}

	list<string> getTeacherList()
	{
		return teachers;
	}
};

int main()
{
	School bloorCI("bloorCI");
	bloorCI.addStudent("John");
	bloorCI.getStudentList().push_back("a");
	bloorCI.getStudentList().push_back("b");
	bloorCI.getTeacherList().push_back("c");
	bloorCI.getInfo();
}

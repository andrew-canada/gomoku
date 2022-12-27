#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string firstName, lastName;
	char gender;
	int age;

public:
	Person(string firstName, string lastName, char gender, int age)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->gender = gender;
		this->age = age;
	}

	void getInfo()
	{
		cout << "Personal Information for " << firstName << ": " << endl;
		cout << "First Name: " << firstName << endl;
		cout << "Last Name: " << lastName << endl;
		cout << "Gender: " << gender << endl;
		cout << "Age: " << age << endl;
	}

	void growUp(int newAge)
	{
		age = newAge;
	}

	void changeGender(char newGender)
	{
		gender = newGender;
	}

	char getGender()
	{
		return gender;
	}
};

int main()
{
	Person andrew("Andrew", "Peng", 'M', 4);
	Person josh("Josh", "Junatas", 'M', 5);
	andrew.getInfo();
	andrew.growUp(14);
	andrew.getInfo();
	josh.growUp(14);
	josh.getInfo();
	josh.changeGender('F');
	if (andrew.getGender() == josh.getGender())
	{
		cout << "Andrew and Josh are the same gender";
	}
	else
	{
		cout << "Andrew and Josh are different genders";
	}
}

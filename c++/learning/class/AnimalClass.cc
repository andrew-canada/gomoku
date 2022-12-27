#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Animal
{
private:
	string name;
	string sound;

public:
	Animal(string name)
	{
		this->name = name;
	}

	Animal(string name, string sound)
	{
		this->name = name;
		this->sound = sound;
	}

	string getName()
	{
		return name;
	}
	string getSound()
	{
		return sound;
	}
};

class Pig : public Animal
{

public:
	Pig(string name, string sound) : Animal(name, sound)
	{
	}
};

class Dog : public Animal
{

public:
	Dog(string name, string sound) : Animal(name, sound)
	{
	}
};

int main()
{
	int numberOfSounds;
	Pig andrew("andrew", "aaa");
	cout << "name of pig: " << andrew.getName() << endl;
	cout << "how many times does pig make sound: ";
	cin >> numberOfSounds;
	cout << "this pig goes: ";
	for (int i = 1; i <= numberOfSounds; i++)
	{
		cout << andrew.getSound() << " ";
	}

	cout << endl;
	Dog ben("ben", "ooo");
	cout << "name of dog: " << ben.getName() << endl;
	cout << "how many times does dog make sound: ";
	cin >> numberOfSounds;
	cout << "this dog goes: ";
	for (int i = 1; i <= numberOfSounds; i++)
	{
		cout << ben.getSound() << " ";
	}
	return 0;
}

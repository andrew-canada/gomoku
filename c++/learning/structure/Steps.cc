#include <iostream>
#include <string>
using namespace std;

struct steps
{
	string name;
	int frontSteps;
	int backSteps;
} andrew;

steps createSteps(int frontSteps, int backSteps);
void print(const steps &personSteps);
//void print(const steps *personSteps);
int main()
{
	andrew.name = "andrew";
	andrew.frontSteps = 5;
	andrew.backSteps = 2;
	steps josh = createSteps(6, 3);
	josh.name = "josh";
	steps ben;
	ben.name = "ben";
	ben.frontSteps = 7;
	ben.backSteps = 4;

	print(andrew);
	print(josh);
	print(ben);
	// print(&andrew);
	// print(&josh);
	// print(&ben);
	return 0;
}

steps createSteps(int frontSteps, int backSteps)
{
	steps personSteps;
	personSteps.frontSteps = frontSteps;
	personSteps.backSteps = backSteps;
	return personSteps;
}

void print(const steps &personSteps)
{
	cout << "Total step distance for " << personSteps.name << " is " << personSteps.frontSteps - personSteps.backSteps << endl;
}

// void print(const steps *personSteps)
// {
// 	cout << "Total step distance for " << personSteps->name << " is " << personSteps->frontSteps - personSteps->backSteps << endl;
// }
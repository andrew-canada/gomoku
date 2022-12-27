#include <iostream>
#include <math.h>
using namespace std;

void bmi()
{
	//bmi calculator
	//weight(kg) / (height *height)
	//underweight <18.5
	//normal 18.5-24.9
	//over >25
	float weight;
	float height;
	cout << "Please enter your weight in kg: ";
	cin >> weight;
	cout << "\nPlease enter your height in m: ";
	cin >> height;
	float bmi = weight / pow(height, 2);
	if (bmi < 18.5)
	{
		cout << "Underweight";
	}
	else if (bmi >= 18.5 && bmi <= 24.9)
	{
		cout << "Normal";
	}
	else
	{
		cout << "Overweight";
	}
}

int main()
{
	bmi();
	return 0;
}

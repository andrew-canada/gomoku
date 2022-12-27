#include "Noise.h"
#include "Person.h"

#include <vector>
using std::vector;
#include <iostream>
using std::cout;
#include <exception>
using std::exception;
using std::out_of_range;

int main()
{
	vector<int> v;
	v.push_back(1);
	int j = v.at(99);
	return 0;
}


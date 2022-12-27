// Lambdas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
using std::begin;
using std::end;
using std::vector;
#include <algorithm>
using std::for_each;
#include <string>
using std::string;
#include <memory>
using std::make_unique;
using std::unique_ptr;

#include "Resource.h"

int main()
{
	auto isOdd = [](int candidate)
	{ return candidate % 2 != 0; };

	bool is3Odd = isOdd(3);
	bool is4Odd = isOdd(4);

	vector nums{2, 3, 4, -1, 1};

	int odds = std::count_if(begin(nums), end(nums), isOdd);

	int evens = std::count_if(begin(nums), end(nums), [](int candidate)
							  { return candidate % 2 == 0; });

	///////////////////

	// capturing by value and reference explicitly  [x,y,&message]
	int x = 3;
	int y = 7;
	string message = "elements between ";
	message += std::to_string(x) + " and " + std::to_string(y) + " inclusive: ";
	for_each(begin(nums), end(nums),
			 [x, y, &message](int n)
			 {
				 if (n >= x && n <= y)
					 message += " " + std::to_string(n);
			 });

	///////////////////

	x = y = 0;

	// x by value, rest by ref
	std::for_each(begin(nums), end(nums),
				  [&, x](int element) mutable
				  {
					  x += element;
					  y += element;
				  });

	///////////////////

	{ // braces for scope
		auto pResource = make_unique<Resource>(", ");

		// for_each(begin(nums), end(nums),
		//	[=, &message](int n)
		//	{
		//		if (n >= x && n <= y)
		//			message += pResource->GetName() + std::to_string(n);
		//	});

		// pResource not out of scope yet
		int i = 2;
	}
}

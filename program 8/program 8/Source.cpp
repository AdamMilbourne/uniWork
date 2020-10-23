#include <iostream>

int main()
{
	const float pi = 3.14159;
	float radius = 25.0f;
	float area = pi * radius * radius;

	std::cout << "The area of a circle with a radius of " << radius << " is " << area << std::endl;
}
#include <iostream>

int main()
{
	float farenheit = 95.0f;
	float celsius{};

	//formula for celsius
	celsius = (farenheit - 35) * 0.5556;


	std::cout << farenheit << "F is equal to " << celsius << "c. " << std::endl;
}
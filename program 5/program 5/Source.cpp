#include <iostream>

int main()
{
	//initialise num to 1
	int num = 1;

	std::cout << "num = " << num << std::endl;
	std::cout << "Increment Operator before num = " << ++num << std::endl;
	std::cout << "num after = " << num << std::endl;

	//reset num to 1
	num = 1;

	std::cout << "num = " << num << std::endl;
	std::cout << "Increment Operator after num = " << num++ << std::endl;
	std::cout << "num after  = " << num << std::endl;

	//reset num to 1
	num = 1;

	std::cout << "num = " << num << std::endl;
	std::cout << "decrement Operator before num = " << --num << std::endl;
	std::cout << "num after  = " << num << std::endl;

	//reset num to 1
	num = 1;

	std::cout << "num = " << num << std::endl;
	std::cout << "decrement Operator after num = " << num-- << std::endl;
	std::cout << "num after  = " << num << std::endl;

	return 0;


}
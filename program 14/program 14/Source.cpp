#include <iostream>

int main()
{
	int num1{}, num2{}, num3{}, sum{}, mean{};

	std::cout << "enter 1 number" << std::endl;
	std::cin >> num1;

	std::cout << "enter another number" << std::endl;
	std::cin >> num2;

	sum = num1 + num2;
	mean = (num1 + num2) / 2;
	std::cout << "The sum is: " << sum << " The mean is: " << mean << std::endl;

	std::cout << "enter a 3rd number" << std::endl;
	std::cin >> num3;

	sum = sum + num3;
	mean = (num1 + num2 + num3) / 3;
	std::cout << "The sum is: " << sum << " The mean is: " << mean << std::endl;
	
	
}
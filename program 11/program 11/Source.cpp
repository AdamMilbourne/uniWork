#include <iostream>

int main()
{
	int num1, num2, num3, num4;
	int playerInput;

	//pick the weather
	std::cout << "1: sunny, 2:cloudy, 3:raining, 4:Exit " << std::endl;

	//read response
	std::cin >> playerInput;

	switch (playerInput)
	{
	case 1:
		std::cout << "Don't forget your sunglasses" << std::endl;
		break;

	case 2:
		std::cout << "Don't forget your coat" << std::endl;
		break;

	case 3:
		std::cout << "Don't forget your umbrella" << std::endl;
		break;

	case 4:
		std::cout << "goodbye" << std::endl;
		break;

		return 0;
	}
}
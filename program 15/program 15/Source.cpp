#include <iostream>

int main()
{
	int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10;
	int PlayerInput;
	char playerdecision;
	playerdecision ='Y';


	while (playerdecision == 'Y'|| playerdecision == 'y')
	{
	

		//pick number
		std::cout << "please enter a number between 1 and 10" << std::endl;

		//players response
		std::cin >> PlayerInput;

		switch (PlayerInput)
		{
		case 1:
			std::cout << "*" << std::endl;
			break;
		case 2:
			std::cout << "*" << std::endl;
			std::cout << "**" << std::endl;
			break;
		case 3:
			std::cout << "*" << std::endl;
			std::cout << "**" << std::endl;
			std::cout << "***" << std::endl;
			break;
		case 4:
			std::cout << "*" << std::endl;
			std::cout << "**" << std::endl;
			std::cout << "***" << std::endl;
			std::cout << "****" << std::endl;
			break;
		case 5:
			std::cout << "*" << std::endl;
			std::cout << "**" << std::endl;
			std::cout << "***" << std::endl;
			std::cout << "****" << std::endl;
			std::cout << "*****" << std::endl;
			break;
		case 6:
			std::cout << "*" << std::endl;
			std::cout << "**" << std::endl;
			std::cout << "***" << std::endl;
			std::cout << "****" << std::endl;
			std::cout << "*****" << std::endl;
			std::cout << "******" << std::endl;
			break;
		case 7:
			std::cout << "*" << std::endl;
			std::cout << "**" << std::endl;
			std::cout << "***" << std::endl;
			std::cout << "****" << std::endl;
			std::cout << "*****" << std::endl;
			std::cout << "******" << std::endl;
			std::cout << "*******" << std::endl;
			break;
		case 8:
			std::cout << "*" << std::endl;
			std::cout << "**" << std::endl;
			std::cout << "***" << std::endl;
			std::cout << "****" << std::endl;
			std::cout << "*****" << std::endl;
			std::cout << "******" << std::endl;
			std::cout << "*******" << std::endl;
			std::cout << "********" << std::endl;
			break;
		case 9:
			std::cout << "*" << std::endl;
			std::cout << "**" << std::endl;
			std::cout << "***" << std::endl;
			std::cout << "****" << std::endl;
			std::cout << "*****" << std::endl;
			std::cout << "******" << std::endl;
			std::cout << "*******" << std::endl;
			std::cout << "********" << std::endl;
			std::cout << "*********" << std::endl;
			break;
		case 10:
			std::cout << "*" << std::endl;
			std::cout << "**" << std::endl;
			std::cout << "***" << std::endl;
			std::cout << "****" << std::endl;
			std::cout << "*****" << std::endl;
			std::cout << "******" << std::endl;
			std::cout << "*******" << std::endl;
			std::cout << "********" << std::endl;
			std::cout << "*********" << std::endl;
			std::cout << "**********" << std::endl;
			break;


		}
		std::cout << "would you like yo go again [Y or N]" << std::endl;
		std::cin >> playerdecision;

		if (playerdecision == 'N' || playerdecision == 'n')
		{
			std::cout << "goodbye" << std::endl;
		}

	}
}


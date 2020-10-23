#include <iostream>

int main()
{
	char userStatus;
	int usersGameChoice;

	std::cout << "tell me your status 's' for student, 't' for teacher or 'o' for other" << std::endl;
	std::cin >> userStatus;

		std::cout << "which game would you like 1 or 2" << std::endl;
		std::cin >> usersGameChoice;
		
		if ((userStatus == 's' || userStatus == 't') && usersGameChoice == 1)
		{
			std::cout << "you can now recieve your 20 percent discount" << std::endl;
        }

		else if ((userStatus == 's' || userStatus == 't') && usersGameChoice == 2)
		{
			std::cout << "you can now recieve your 10 percent discount" << std::endl;
		}

		else
		{
			std::cout << "you are not eligible for a discount" << std::endl;
		}
	}

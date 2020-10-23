#include <iostream>

int main()
{
	int num1, num2;
	int answer{};
	int numtemp{};
	
	std::cout << "tell me is its raining with 1 or snowing with 2" << std::endl;

	std::cin >> answer;

	switch (answer)
	{
	case 1:
	{
		std::cout << "tell me the tempurature in celsius" << std::endl;
		std::cin >> numtemp;
		break;
	}
	case 2:
	{
		std::cout << "tell me the tempurature in celsius" << std::endl;
		std::cin >> numtemp;
		break;
	}
	}
	if (answer = 1)
	{
		 if (numtemp>15)
		{
			std::cout << "wear a light raincoat" << std::endl;
		}
		 else
		{
			 std::cout << "wear a thick coat" << std::endl;
	    }

	}

	else if (answer = 2)
	{
		if (numtemp > 5)
		{
			std::cout << "wear something warm" << std::endl;
		}

		else if (numtemp > 0)
		{
			std::cout << "wrap up warm" << std::endl;
		}

		else
		{
			std::cout << "stay at home" << std::endl;
		}

	}
	else
	{
		std::cout << "have a nice day" << std::endl;
	}

}
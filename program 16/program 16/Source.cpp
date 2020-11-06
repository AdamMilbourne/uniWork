#include <iostream>

int main()
{
	int playerlife = 100;
	int playerdamagetaken;

	//tell them whhat the life is
	std::cout << "The players life is: " << playerlife << std::endl;

	//while players health is above 0 do this
	while (playerlife > 0)
	{
		
		//do these questions till i = 10 or in other words ask question 10 times
		for(int i = 1; i < 11; i++)
		{
			//which question is being displayed
			std::cout << "Question " << i << ": How much damage shall i deal?\n";

			//how much damage is being done
			std::cin >> playerdamagetaken;

			//player life now equals this 
			playerlife = playerlife - playerdamagetaken;

			//debug to check player health is changing
			//std::cout << "The players life is: " << playerlife << std::endl;
			if (playerlife < 1)
			{
				std::cout << "Early end. Player Died!" << std::endl;
				break;
			}
		}		
		break;
	}
	if (playerlife > 0)
	{
		std::cout << "All questions asked. player survived!\n" << "players health was: " << playerlife << std::endl;
	}
}
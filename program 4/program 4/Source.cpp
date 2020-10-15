#include <iostream>

int main()
{
	typedef int cost;
	cost CurrentCost = 13000;
	enum carmake
	{
		Ford = 1,
		Fiat,
		TESLA,
		VW,
		BMW,
		ASTONMARTIN,
		HONDA,
		NISSAN,
		TOYOTA,
		AUDI,
		JAGUAR,
		DODGE
	};
	carmake CarID;
	CarID = HONDA;
	std::cout << "the cost of my car is: " << CurrentCost << std::endl;
	std::cout << "My car ID is: " << CarID << std::endl;
}
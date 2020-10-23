#include <iostream>

int main()
{
		float mySavings = 2000.0f;
		float yourPercentage = 50.0f;
		float yourShare = (mySavings * (yourPercentage / 100.0f));

		std::cout << "Your share: " << yourShare << std::endl;

		return 0;
}
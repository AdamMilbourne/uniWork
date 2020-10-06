

#include <iostream>
using namespace std;

int main()
{
	bool a = false;
	bool b = true;

	int num1 = 12, num2 = 5, num3 = 7;

	if (a)
	{
		num1 += 10;
		num2 += 15;		
	}
	
    
	else if (b)
	{
		num1++;
		num3 += 20;

	}
	else
	{
		num1--;
		num2--;
		num3--;
	}

	std::cout << "num1 =" << num1 << endl;
	std::cout << "num2 =" << num2 << endl;
	std::cout << "num3 =" << num3 << endl;
}

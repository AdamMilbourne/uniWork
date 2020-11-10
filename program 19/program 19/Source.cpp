#include <iostream>
using namespace std;
int oddOrEven(int num1, int Odd)
{
	if (num1 % 2 == 0)
	{
		Odd = 0;
	}
	else
	{
		Odd = 1;
	}
	return Odd;
}
int main()
{
	int num1{}, num2{}, num3{}, num4{}, num5{}, num6{}, num7{}, num8{}, num9{}, num10{}, numOfOdd{}, Oddtotal{}, numOfEven{}, evenTotal{};
	int Odd = 1;
	cout << "pick 10 numbers" << endl;
	for (int i = 1; i < 11; i++)
	{
		cin >> num1;
		oddOrEven(num1, Odd);
		Odd = oddOrEven(num1, Odd);
		if (Odd == 1)
		{
			numOfOdd = numOfOdd + 1;
			Oddtotal = Oddtotal + num1;
			cout << "is Odd" << endl;
		}
		else
		{
			numOfEven = numOfEven + 1;
			evenTotal = evenTotal + num1;
			cout << "is Even" << endl;
		}
	}
	cout << "Number of odds are: " << numOfOdd << " Grand total of all odds is: " << Oddtotal << "Number of evens are: " << numOfEven << " Grand total of all evens is: " << evenTotal << endl;
}
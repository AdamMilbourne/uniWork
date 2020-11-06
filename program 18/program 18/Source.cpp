#include <iostream>
using namespace std;

int smallestnumber(int num1, int num2)
{
	int min{};
	int max{};
	if (num1 < num2)
	{
		min = num1;
		max = num2;
	}
	if (num2 < num1)
	{
		min = num2;
		max = num1;
	}
	if (num1 == num2)
	{
		min = num1;
		max = num2;
		cout << "they are the same so the minimum is: " << endl;
	}
	return min;
}
int main()
{
	int num1{}, num2{};
	
	cout << "enter 2 numbers" << endl;
	cin >> num1;
	cin >> num2;
	int result = smallestnumber(num1, num2);

	cout << "The result is: " << result << endl;

	return 0;
}


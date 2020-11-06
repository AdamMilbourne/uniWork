#include <iostream>
using namespace std;

int main()
{
	float sum{}, mean{}, num1{}, num2{}, Newestnum{};

	cout << "enter two numbers\n";
	cin >> num1;
	cin >> num2;


	sum = (num1 + num2);
	mean = (sum / 2);
	cout << "sum: " << sum << " mean: " << mean << endl;

	for (int i = 2; i++;)
	{
		cout << "enter another number or 0 to exit" << endl;
		cin >> Newestnum;
		if (Newestnum == 0)
		{
			cout << "thanks for playing" << endl;
			break;
		}
		sum = (sum + Newestnum);
		mean = (sum / i);
		cout << "sum: " << sum << " mean: " << mean << endl;
	}
}




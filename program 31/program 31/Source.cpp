#include<iostream>
using namespace std;

int main()
{
	int count = 4;

	for (int i = 1; i < count; i++)
	{
		
		if (i % 2 == 0)
		{
			cout << i;
			cout << " is an even number" << endl;
		}
		else
		{
			cout << i;
			cout << " is an odd number" << endl;
		}
	}

	//pause output
	cin.get();
	return 0;
}
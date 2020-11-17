
#include <iostream>
using namespace std;

int findsmallestelement(int arr[], int n)
{
	int i = 0;
	int temp = arr[0];
	for (i; i < n; i++)
	{
		if (temp > arr[i])
		{
			temp = arr[i];
		}
	}
	
	cout << "in position: ";
	return temp;
}

int main()
{
	const int n = 10;
	int arr[n];

	for (int i = 0; i < 10; i++)
	{
		cout << "enter a number" << endl;
		cin >> arr[i];
	}
	int smallest = findsmallestelement(arr, n);
	cout << " The smallest number is: " << smallest;
	return 0;
	}



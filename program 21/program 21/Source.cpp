
#include <iostream>
#include <iomanip>
using namespace std;


int findsmallestelement(int arr[], int n, int i)
{
	
	int temp = arr[0];
	for (i; i < n; i++)
	{
		if (temp > arr[i])
		{
			temp = arr[i];
		}
	}
	cout << "smallest number is in position: " << i << endl;
	cout << "position 1 2 3 4 5 6 7 8 9 10" << endl;
	return temp;
}



int main()
{
	int i = 0;
	const int n = 10;
	int arr[n];

	for (int i = 0; i < 10; i++)
	{
		cout << "enter a number" << endl;
		cin >> arr[i];
	}
	int smallest = findsmallestelement(arr, n, i);
	cout << setw(11);
	for (int j = 0; j < 10; j++)
	{
		cout << arr[j] << setw(2);
	}
	cout << " The smallest number is: " << smallest;
	return 0;
	}



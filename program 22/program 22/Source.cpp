#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int findLargestElement(int arr[], int a, int o)
{
	int temp = arr[0];
	for (o < a; o++;)
	{
		if (temp < arr[o])
		{
			temp = arr[o];
		}
	}
	cout << "Largest number is in position: " << o << endl;
	return temp;
}

int main()
{
	int temp;
	int arr[5];
	int n = sizeof(arr) / sizeof(arr[0]);
	const int a = 5;
	int o = 0;

	//user pick 5 numbers
	cout << "please pick 5 numbers" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "number" << i << endl;
		cin >> arr[i];
	}

	//show elements as typed
	cout << "Unsorted Array elements:" << endl;
	for (int p = 0; p < 5; p++)
		cout << arr[p] << "\t";
	cout << endl;

	//sort in ascending order
	sort(arr, arr + n);
	
	//output in order
	cout << "Sorted (Ascending Order) Array elements:" << endl;
	for (int j = 0; j < 5; j++)
		cout << arr[j] << "\t";
	cout << endl;

	//sort descending
	sort(arr, arr + n, greater<int>());

	cout << "sorted (Descending Order) Array elements:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << "\t";
	}
		cout << endl;

		int largestelement = findLargestElement(arr, a, o);
		cout <<  "The largest number is: " << largestelement;

		return 0;
	}



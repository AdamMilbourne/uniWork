#include <iostream>

using namespace std;

void plus25(int& rNum);

void minus25(int& rNum);

int main()
{
	int num;
	cout << "please pick a number" << endl;
	cin >> num;
	cout << "The value of num is: " << num << endl;
	plus25(num);
	cout << "the value of num is: " << num << endl;
	cout << "please pick a second number" << endl;
	cin >> num;
	cout << "the value of num is: " << num << endl;
	minus25(num);
	cout << "the value of num is: " << num << endl;
}

void plus25(int& rNum)
{
	int temp = rNum;
	temp = temp + 25;
	cout << temp << endl;
	rNum = temp;
	cout << "rNum is: " << rNum << endl;

}

void minus25(int& rNum)
{
	int temp = rNum;
	temp = temp - 25;
	rNum = temp;
	cout << "rNum is: " << rNum << endl;
}
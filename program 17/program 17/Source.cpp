#include <iostream>
using namespace std;

void addtwo(int num)
{
	//add two to number passed
	num += 2;
	// output contents of num within function
	cout << "FUNCTION: num = " << num << endl;
}
int main()
{
	int mynum = 6;
	cout << "MAIN [BEFORE]: mynum = " << mynum << endl;

	addtwo(mynum);
	cout << "MAIN [AFTER]: mynum = " << mynum << endl;
}
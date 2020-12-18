#include <iostream>

using namespace std;

void inputDetails(int* n1, int* n2);
void outpurDetails(int& integer1, int& integer2, int* pointer);

int main()
{
    int num1, num2;

    inputDetails(&num1, &num2);

    cout << num1 << endl << num2 << endl;

    int* pNum = &num1;

    outpurDetails(num1, num2, pNum);
}

void inputDetails(int* n1, int* n2)
{
    cout << "please input a number" << endl;
    cin >> *n1;
    cout << "please input another number" << endl;
    cin >> *n2;
}

void outpurDetails(int& integer1, int& integer2, int* pointer)
{
    cout << "num1 value: " << integer1 << endl;
    cout << "num1 address in memory: " << &integer1 << endl;
    cout << "num2 value: " << integer2 << endl;
    cout << "num2 address in memory: " << &integer2 << endl;
    cout << "pNum value: " << pointer << endl;
    cout << "pNum dereferenced value: " << *pointer << endl;
    cout << "pNum address in memory: " << &pointer << endl;
}

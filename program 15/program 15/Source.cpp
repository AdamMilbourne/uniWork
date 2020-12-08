#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
    char userinput = 'y';
    while (userinput == 'y' || userinput == 'Y')
    {
        cout << "enter a number between 1 and 10.\n";
        char star = '*';
        int input;
        char playAgain;
        cin >> input;
        for (int i = 0; i < input + 1; i++)
        {
            cout << endl;
            for (int j = 0; j < i; j++)
            {
                cout << star;
            }
        }
        cout << "\nwould you like to play again? press y for yes and n for no." << endl;
        cin >> userinput;
    }
    if (userinput == 'n' || userinput == 'N')
    {
        cout << "\ngoodbye" << endl;
        Sleep(1000);
    }
}


#include <iostream>
#include <cctype>
using namespace std;
int main()
{
    char name[50] = { ' ' };
    cout << "Input your first initial, middle initial and full surname." << endl;
    cin.getline(name, 50);
    for (int i = 0; i < strlen(name); i++)
        cout << (std::isspace(name[i]) ? '\n' : name[i]);
}
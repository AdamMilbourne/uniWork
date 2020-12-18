#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void main()
{
	string name;
	cout << "enter your name\n";
	cin >> name;

	string sentence = "Do you know who loves C++ XX does!";

	int pos = sentence.find("XX");

	sentence.insert(pos + 1, name, 0, name.length());

	cout << sentence << endl;

	sentence.replace(pos, size(name) + 2, name);

	cout << sentence << endl;

	string name2;
	cout << "enter another name\n";

	while (true)
	{
		cin >> name2;
		if (name.length() >= name2.length())
		{
			cout << "please enter a longer name than the first one." << endl << "please try again" << endl;
		}
		else
		{
			break;
		}
	}

	int pos2 = sentence.find(name);

	sentence.replace(pos, size(name), name2);

	cout << sentence << endl;
}

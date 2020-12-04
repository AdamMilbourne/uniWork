#include <iostream>
using namespace std;

int main()
{
	char choiceStaff = 'I';
	const int MAX_ITEMS = 4;
	int numItems = 0;
	string inventory[MAX_ITEMS];
	inventory[numItems++] = "sword";
	inventory[numItems++] = "battle axe";
	inventory[numItems++] = "healing potion";
	inventory[numItems++] = "dagger";
	
	cout << "You have picked up a wizards staff!!\n Would you like to swap it for the dagger in your inventory?" << endl;
		
	while (choiceStaff != 'y' || choiceStaff != 'Y' || choiceStaff != 'n' || choiceStaff != 'N' || choiceStaff == 'I')
	{
		cout << "press y for yes and n for no." << endl;
		cin >> choiceStaff;

		if (choiceStaff == 'y' || choiceStaff == 'Y')
		{
			inventory[3] = "Wizard Staff";
			break;
		}
		else if (choiceStaff == 'n' || choiceStaff == 'N')
		{
			cout << "you have left the staff behind" << endl;
			break;
		}
	}
	cout << "\nIn your inventory is: " << endl;
	for (int i = 0; i < 4; i++) {
		cout << inventory[i] << endl;
	}

	cout << "\nthanks for playing" << endl;
	return 0;
}
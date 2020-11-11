#include <iostream>
using namespace std;

int playerHealth = 1000, enemyHealth = 2000;
bool Playing = true;

bool playState(bool Playing)
{
	Playing = true;
	char playAgain;
	if (enemyHealth <= 0)
	{
		cout << "You have beaten the troll" << endl;
		cout << "Would you like to play again y/n" << endl;
		cin >> playAgain;
		if (playAgain == 'y' || playAgain == 'Y')
		{
			enemyHealth = 2000;
			playerHealth = 1000;
			Playing = true;
			return Playing;
		}
		if (playAgain == 'n' || playAgain == 'N')
		{
			Playing = false;
			return Playing;
		}
	}	
	if (playerHealth <= 0)
	{
		cout << "You have been killed" << endl;
		cout << "Would you like to play again y/n" << endl;
		cin >> playAgain;
		if (playAgain == 'y' || playAgain == 'Y')
		{
			enemyHealth = 2000;
			playerHealth = 1000;
			Playing = true;
			return Playing;
		}
		if (playAgain == 'n' || playAgain == 'N')
		{
			Playing = false;
			return Playing;
		}	

	}	
}

int attackNothing()
{
	return 0;
}

int attackChoice(int playerChoice)
{
	int num1, num2, num3;
	const int swordDamage = 300, magicDamage = 650, axeDamage = 450, trollSword = 350, trollMagic = 50, trollAxe = 100;
	switch (playerChoice)
	{
	case 1:
		enemyHealth = enemyHealth - swordDamage;
		playerHealth = playerHealth - trollSword;
		cout << "*THWACK* You have hit the troll" << endl;
		cout << "*SWISH* You have been hit" << endl;
		if (playerHealth < 0)
		{
			playerHealth = 0;
		}
		if (enemyHealth < 0)
		{
			enemyHealth = 0;
		}
		cout << "Your health is: " << playerHealth << endl;
		cout << "Enemy health is: " << enemyHealth << endl;
		break;
	case 2:
		cout << "this is choice 2" << endl;
		break;
	case 3:
		cout << "this is choice 3" << endl;
		break;
	}
	return 0;
}

int main()
{	
	int playerChoice{};
	playState(Playing);
	cout << "You have encountered a troll, you have 3 choices of attack" << endl;
	while (Playing == true)
	{
		cout << "1. Use sword, 2. Use magic, 3. Use axe\n Your sword will do little damage but quickly,\n your magic will do large amounts of magic damage very slowly,\n your axe will do a medium amount of damage at a medium speed" << endl;
		cin >> playerChoice;
		attackChoice(playerChoice);
		if (playerHealth == 0 || enemyHealth == 0)
		{
			playState(Playing);
		}
	
	}
	if (Playing == false)
	{
		cout << "Thanks for playing" << endl;
	}
	
}
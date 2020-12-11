#include<iostream>
#include<stdlib.h>
using namespace std;

char arrBoardCards[10] = { 'A', 'B', 'C', 'D', 'E', 'E', 'D', 'C', 'B', 'A' };

bool arrCardsFound[10] = { false };
int attemptCount;

int main()
{

	int Score = 0;
	bool Playing = true;

	while (Playing == true)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "[" << arrBoardCards[i] << "]";
		}
		cout << endl;
		for (int i = 5; i < 10; i++)
		{
			cout << "[" << arrBoardCards[i] << "]";
		}
		int guess1, guess2;

		cout << "\nplease pick your first card" << endl;
		cin >> guess1;
		//Drawboard(guess1);

		cout << "please pick your second card" << endl;
		cin >> guess2;
		//Drawboard(guess2);

		//check results
		/*if (check guesses match)
		{
			if( match == true)
			{
			Score++
			}
			arrCardsFound[] = true;
			arrCardsFound[] = true;
		}
		else
		{
			//no match
		}
		if (Score == 5)
		{
			cout << "you have won" << endl;
			playing = !playing;
			//break;
		}
		else
		{
			attempts++
		}

		*/
	}
}

int DrawBoard()
{
	system("cls");
	
	cout << "you have had" << attemptCount << "attempts." << endl;

	for (int i = 0; i < 10; i++)
	{
		if (arrCardsFound[i])
		{
			cout << "[" << arrBoardCards[i] << "]";
		}
		else
		{
			cout << "[" << i + 1 << "]";
		}
		if (i == 4)
		{
			//split board
		}
	}
	return 0;
}

 
int Drawboard(int guess1, int guess2)
{
	system("cls");

	cout << "you have had" << attemptCount << "attempts." << endl;

	for (int i = 0; i < 10; i++)
	{
		if (arrCardsFound[i] || i + 1 == guess1 || i + 1 == guess2)
			cout << "[" << arrBoardCards[i] << "]" << endl;

		else
			cout << "[" << i << "]" << endl;

		if (i == 4)
		{
			//split board
		}
	}
	return 0;
}


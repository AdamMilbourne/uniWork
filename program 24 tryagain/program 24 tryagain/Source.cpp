#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

char cards[10] = { 'A', 'B', 'C', 'D', 'E', 'E', 'D', 'C', 'B', 'A' };

bool cardsFound[10] = { false, false, false, false, false, false, false, false, false, false };

int attemptCounter = 0;

void drawBoard();

void drawBoard(int guess1);

void drawBoard(int guess1, int guess2);

void main()
{
	int score = 0;
	bool playing = true;
	bool guess1Check = false, guess2Check = false;
	while (playing)
	{
		drawBoard();
		int guess1, guess2;
		while (!guess1Check)
		{
			cout << "pick a Card\n";
			cin >> guess1;
			if (!cardsFound[guess1 - 1])
			{
				break;
			}
			else
			{
				cout << "You have already found this pair\ntry again\n";
				Sleep(1000);
			}
		}
		drawBoard(guess1);
		while (!guess2Check)
		{
			cout << "pick another space\n";
			cin >> guess2;
			if (!cardsFound[guess2 - 1] && guess1 != guess2)
			{
				break;
			}
			else
			{
				cout << "You have already found this pair or is the same guess as your first card\ntry again\n";
				
			}
		}
		drawBoard(guess1, guess2);

		if (cards[guess1 - 1] == cards[guess2 - 1])
		{
			cout << "You found a pair\n";
			Sleep(1000);
			score++;
			cardsFound[guess1 - 1] = true;
			cardsFound[guess2 - 1] = true;
			
		}
		else
		{
			cout << "you did not find a pair \npress enter to try again?";
			cin.ignore();
			cin.ignore();
		}
		if (score == 5)
		{
			playing = false;
		}
		else
		{
			attemptCounter++;
		}
	}
	cout << "YOU WON !!!!!";
}

void drawBoard()
{
	system("cls");
	cout << attemptCounter << endl;
	for (int i = 0; i < 10; i++)
	{
		if (cardsFound[i] == true)
		{
			cout << "[" << cards[i] << "] ";
		}
		else
		{
			cout << "[" << i + 1 << "] ";
		}
		if (i == 4)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void drawBoard(int guess1)
{
	system("cls");
	cout << attemptCounter << endl;
	for (int i = 0; i < 10; i++)
	{
		if (cardsFound[i] == true || guess1 - 1 == i)
		{
			cout << "[" << cards[i] << "] ";
		}
		else
		{
			cout << "[" << i + 1 << "] ";
		}
		if (i == 4)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void drawBoard(int guess1, int guess2)
{
	system("cls");
	cout << attemptCounter << endl;
	for (int i = 0; i < 10; i++)
	{
		if (cardsFound[i] == true || guess1 - 1 == i || guess2 - 1 == i)
		{
			cout << "[" << cards[i] << "] ";
		}
		else
		{
			cout << "[" << i + 1 << "] ";
		}
		if (i == 4)
		{
			cout << endl;
		}
	}
	cout << endl;
}

#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(char p_marker) : Player(p_marker)
{
	m_input = 0;
}

int HumanPlayer::DecideMove(Grid* p_grid)
{
	m_input = 0;
	if (HasAvailableMoves(p_grid))
	{
		cout << "Player " << m_marker << "'s turn! Input a number 1-9 to place your marker! Input 0 to quit: ";
		cin >> m_input;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');


		ValidateInput();
	}
	return m_input;
}

void HumanPlayer::ValidateInput()
{
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input - Input a number 1-9 to place your marker! Input 0 to quit: ";
			cin >> m_input;
		}
		else break;
	}
}

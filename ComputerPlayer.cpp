#include "ComputerPlayer.h"

#include <ctime>

ComputerPlayer::ComputerPlayer(char p_marker) : Player(p_marker)
{
	srand(time(nullptr));
}

int ComputerPlayer::DecideMove(Grid* p_grid)
{
	if (!HasAvailableMoves(p_grid))
		return 0;

	cout << "Computer player is deciding...\n";
	Sleep(1000);

	return RandomSelection();
}

int ComputerPlayer::RandomSelection()
{
	return rand() % 9 + 1;
}

int ComputerPlayer::MiniMax()
{
	char m_maxPlayer = m_marker;
	char m_minPlayer = (m_maxPlayer == 'X')? 'O' : 'X';



	return 0;
}

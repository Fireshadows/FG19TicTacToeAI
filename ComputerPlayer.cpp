#include "ComputerPlayer.h"
#include <ctime>

ComputerPlayer::ComputerPlayer(char p_marker) : Player(p_marker)
{
	srand(time(nullptr));
}

int ComputerPlayer::DecideMove()
{
	cout << "Computer player is deciding...\n";
	return rand() % 9 + 1;
}

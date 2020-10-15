#include "ComputerPlayer.h"

#include <ctime>
#include <vector>

ComputerPlayer::ComputerPlayer(char p_marker) : Player(p_marker)
{
	srand(time(nullptr));
	m_miniMax = new MiniMax(p_marker);
}

int ComputerPlayer::DecideMove(Grid* p_grid)
{
	if (!HasAvailableMoves(p_grid))
		return 0;

	cout << "Player " << m_marker << " is deciding...\n";
	Sleep(1000);

	if (p_grid->GetEmptyTiles().size() == 9)
		return RandomSelection(p_grid);

	return MiniMaxSelection(p_grid);
}

int ComputerPlayer::RandomSelection(Grid* p_grid)
{
	return rand() % 9 + 1;
}

int ComputerPlayer::MiniMaxSelection(Grid* p_grid)
{
	return m_miniMax->Run(p_grid, m_marker)["selection"] + 1;
}
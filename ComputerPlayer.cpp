#include "ComputerPlayer.h"

#include <ctime>
#include <vector>

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

	if (p_grid->GetEmptyTiles().size() == 9)
		return RandomSelection(p_grid);

	return MiniMax(p_grid, m_marker)["selection"] + 1;
}

int ComputerPlayer::RandomSelection(Grid* p_grid)
{
	return rand() % 9 + 1;
}

map<string, int> ComputerPlayer::MiniMax(Grid* p_grid, char p_marker)
{
	map<string, int> m_bestMove;
	map<string, int> m_simulatedMove;

	char m_maxPlayer = m_marker;
	char m_minPlayer = (p_marker == 'X')? 'O' : 'X';

	vector<int> m_emptyTiles = p_grid->GetEmptyTiles();

	
	//If previous move was a winning
	if (p_grid->m_winningMarker == m_minPlayer)
	{
		m_bestMove["selection"] = -1;
		if (m_minPlayer == m_maxPlayer)
			m_bestMove["score"] = 1 * (m_emptyTiles.size() + 1);
		else
			m_bestMove["score"] = -1 * (m_emptyTiles.size() + 1);
		return m_bestMove;
	}
	else if (!p_grid->HasEmptyTiles())
	{
		m_bestMove["selection"] = -1;
		m_bestMove["score"] = 0;
		return m_bestMove;
	}

	m_bestMove["selection"] = -1;
	if (p_marker == m_maxPlayer)
		m_bestMove["score"] = numeric_limits<int>::min();
	else
		m_bestMove["score"] = numeric_limits<int>::max();

	for (int selection : m_emptyTiles)
	{
		//Simulate move at current selection
		p_grid->PlaceMarker(selection, p_marker, false);
		p_grid->CheckVictoryRecord(selection, p_marker);
		m_simulatedMove = MiniMax(p_grid, m_minPlayer);

		//Undo simulation
		p_grid->ClearMarker(selection);
		p_grid->m_winningMarker = ' ';

		m_simulatedMove["selection"] = selection;

		if (p_marker == m_maxPlayer) {
			if (m_simulatedMove["score"] > m_bestMove["score"])
				m_bestMove = m_simulatedMove;
		}
		else {
			if (m_simulatedMove["score"] < m_bestMove["score"])
				m_bestMove = m_simulatedMove;
		}
	}

	return m_bestMove;
}
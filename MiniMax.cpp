#include "MiniMax.h"
#include <vector>

MiniMax::MiniMax(char p_maxPlayer) : m_maxPlayer(p_maxPlayer), m_winningPlayer(' ')
{
}

std::map<string, int> MiniMax::Run(Grid* p_grid, char p_player)
{
	map<string, int> m_bestMove;
	map<string, int> m_simulatedMove;

	char m_otherPlayer = p_player == 'X' ? 'O' : 'X';

	vector<int> m_emptyTiles = p_grid->GetEmptyTiles();

	m_bestMove["selection"] = -1;

	//If previous move was a winning move
	if (m_winningPlayer == m_otherPlayer)
	{
		m_bestMove["score"] = (m_emptyTiles.size() + 1);
		m_bestMove["score"] *= (m_otherPlayer == m_maxPlayer ? 1 : -1);
		return m_bestMove;
	}
	else if (!p_grid->HasEmptyTiles())
	{
		m_bestMove["score"] = 0;
		return m_bestMove;
	}

	if (p_player == m_maxPlayer)
		m_bestMove["score"] = numeric_limits<int>::min();
	else
		m_bestMove["score"] = numeric_limits<int>::max();

	for (int selection : m_emptyTiles)
	{
		//Simulate move at current selection
		p_grid->PlaceMarker(selection, p_player, false);
		if (p_grid->CheckVictory(selection, p_player))
			m_winningPlayer = p_player;
		m_simulatedMove = Run(p_grid, m_otherPlayer);

		//Undo simulation
		p_grid->ClearMarker(selection);
		m_winningPlayer = ' ';

		m_simulatedMove["selection"] = selection;

		if (p_player == m_maxPlayer) {
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